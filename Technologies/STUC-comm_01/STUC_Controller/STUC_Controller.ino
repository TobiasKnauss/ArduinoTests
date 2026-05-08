#include <Arduino.h>
#include <Streaming.h>

#include <STUC.h>
#include <StucData.h>

const uint8_t c_BufferDefaultValue = 0xDD;

const uint16_t c_EepromOffset = 0;

STUC* m_pSTUC;

uint8_t m_PayloadSendBuffer[20];
uint8_t m_PayloadRecvBuffer[20];
uint8_t m_SendBuffer[50];
uint8_t m_ReceiveBuffer[80];

uint32_t            m_WorkerDeviceId      = 0x63691402;
uint16_t            m_CommandId           = 0x1042;
STUC::EChecksumType m_ChecksumType        = STUC::EChecksumType::CRC16;

uint8_t   m_PayloadLength           = 0;
uint16_t  m_ReceiveBufferWriteIndex = 0;
uint16_t  m_ReceiveBufferReadIndex  = 0;
bool      m_DataAvailable           = false;
StucData  m_RequestData;

//--------------------------------------------------------------------
void setup ()
{
  EResult result;

  memset (m_PayloadSendBuffer, 0xFF, sizeof (m_PayloadSendBuffer));
  memset (m_PayloadRecvBuffer, 0xFF, sizeof (m_PayloadRecvBuffer));
  memset (m_SendBuffer       , 0xFF, sizeof (m_SendBuffer));
  memset (m_ReceiveBuffer    , 0xFF, sizeof (m_ReceiveBuffer));

  Serial.begin (9600);
  Serial1.begin (9600);
  delay (2000);

  Serial << F("PayloadSendBuffer Addr=") << _HEX4((uint16_t)m_PayloadSendBuffer) << " Len=" << sizeof (m_PayloadSendBuffer) << endl;
  Memory_PrintLn (m_PayloadSendBuffer, sizeof (m_PayloadSendBuffer));
  Serial << F("PayloadRecvBuffer Addr=") << _HEX4((uint16_t)m_PayloadRecvBuffer) << " Len=" << sizeof (m_PayloadRecvBuffer) << endl;
  Memory_PrintLn (m_PayloadRecvBuffer, sizeof (m_PayloadRecvBuffer));
  Serial << F("SendBuffer        Addr=") << _HEX4((uint16_t)m_SendBuffer)        << " Len=" << sizeof (m_SendBuffer) << endl;
  Memory_PrintLn (m_SendBuffer, sizeof (m_SendBuffer));
  Serial << F("ReceiveBuffer     Addr=") << _HEX4((uint16_t)m_ReceiveBuffer)     << " Len=" << sizeof (m_ReceiveBuffer) << endl;
  Memory_PrintLn (m_ReceiveBuffer, sizeof (m_ReceiveBuffer));

  m_pSTUC = new STUC (c_EepromOffset, result);
  Serial << "STUC ctor Result: " << (int)result << " = " << STUC::GetResultText (result) << endl;
}

//--------------------------------------------------------------------
void loop ()
{
  EResult result;

  if (Serial.available ())
  {
    Serial << "Serial available: " << Serial.available () << endl;

    // Receive all available data
    while (Serial.available () > 0
        && m_PayloadLength < sizeof (m_PayloadSendBuffer))
    {
      m_PayloadSendBuffer[m_PayloadLength++] = Serial.read ();
    }
  }

  if (m_PayloadLength > 0)
  {
    Serial << F("PayloadSendBuffer: bytes used = ") << m_PayloadLength << endl;
    Memory_PrintLn (m_PayloadSendBuffer, sizeof (m_PayloadSendBuffer));

    m_RequestData = StucData (STUC::EAction::Read, m_WorkerDeviceId, m_CommandId);
    m_RequestData.SetPayloadInfo (m_PayloadSendBuffer,
                                  sizeof (m_PayloadSendBuffer),
                                  m_PayloadLength);
    uint16_t requestMessageLength = 0;

    result = m_pSTUC->ComposeRequest (m_RequestData,
                                      m_SendBuffer,
                                      sizeof (m_SendBuffer),
                                      requestMessageLength);
    Serial << F("STUC.ComposeRequest() result=") << STUC::GetResultText (result) << endl;

    Serial << F("SendBuffer: bytes used = ") << requestMessageLength << endl;
    Memory_PrintLn (m_SendBuffer, sizeof (m_SendBuffer));

    if (result == EResult::SUCCESS)
    {
      Serial1.write (m_SendBuffer, requestMessageLength);
      Serial1.flush ();
    }

    memset (m_PayloadSendBuffer, c_BufferDefaultValue, m_PayloadLength);
    memset (m_SendBuffer,        c_BufferDefaultValue, requestMessageLength);
    m_PayloadLength = 0;
  }

  if (Serial1.available ())
  {
    Serial << "Serial1 available: " << Serial1.available () << endl;

    // Receive all available data
    while (Serial1.available ())
    {
      m_ReceiveBuffer[m_ReceiveBufferWriteIndex++] = Serial1.read ();
      if (m_ReceiveBufferWriteIndex >= sizeof (m_ReceiveBuffer))
        m_ReceiveBufferWriteIndex = 0;
    }

    Serial << F("ReceiveBuffer: position = ") << m_ReceiveBufferWriteIndex << endl;
    Memory_PrintLn (m_ReceiveBuffer, sizeof (m_ReceiveBuffer));

    m_DataAvailable = true;
  }

  if (m_DataAvailable)
  {
    StucData replyData;
    replyData.SetPayloadInfo (m_PayloadRecvBuffer, sizeof (m_PayloadRecvBuffer));
    STUC::EMessageType replyMessageType   = STUC::EMessageType::None;
    uint8_t          replyMessageLength = 0;

    result = m_pSTUC->AnalyseMessage (m_ReceiveBuffer,
                                      sizeof (m_ReceiveBuffer),
                                      m_ReceiveBufferReadIndex,
                                      replyData,
                                      replyMessageType,
                                      replyMessageLength);
    Serial << F("STUC.AnalyseMessage() result=") << STUC::GetResultText (result) << endl;

    Serial << F("Message Type:        ") << (uint8_t)replyMessageType         << endl;
    Serial << F("Action:              ") << (uint8_t)replyData.Action         << endl;
    Serial << F("Remote Device Id:    ") << _HEX8 (replyData.RemoteDeviceId)  << endl;
    Serial << F("Message Id:          ") << replyData.MessageId               << endl;
    Serial << F("Timestamp:           ") << replyData.Timestamp               << endl;
    Serial << F("CommandId:           ") << replyData.CommandId               << endl;
    Serial << F("Result:              ") << (uint8_t)replyData.MessageResult  << endl;
    Serial << F("Payload Data Length: ") << replyData.PayloadLength           << endl;
    Serial << F("Message Length:      ") << replyMessageLength                << endl;

    Serial << F("PayloadRecvBuffer: bytes used = ") << replyData.PayloadLength << endl;
    Memory_PrintLn (m_PayloadRecvBuffer, sizeof (m_PayloadRecvBuffer));

    if (result == EResult::SUCCESS)
    {
      RingBuffer_SetValueBackward (m_ReceiveBuffer,
                                   sizeof (m_ReceiveBuffer),
                                   m_ReceiveBufferReadIndex,
                                   replyMessageLength,
                                   c_BufferDefaultValue);
      Serial << F("ReceiveBuffer:") << endl;
      Memory_PrintLn (m_ReceiveBuffer, sizeof (m_ReceiveBuffer));

      // Evaluate reply

      memset (m_PayloadRecvBuffer, c_BufferDefaultValue, replyData.PayloadLength);
      Serial << F("PayloadRecvBuffer:") << endl;
      Memory_PrintLn (m_PayloadRecvBuffer, sizeof (m_PayloadRecvBuffer));
    }
    else
      m_DataAvailable = false;
  }

  if (!m_DataAvailable)
  {
    Serial.println ("Idle.");
    delay (1000);
  }
}
