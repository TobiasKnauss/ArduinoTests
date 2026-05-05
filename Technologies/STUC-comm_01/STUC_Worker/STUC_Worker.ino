#include <Arduino.h>
#include <Streaming.h>
#include <STUC.h>

const uint8_t c_BufferDefaultValue = 0xDD;

STUC* m_pSTUC;

uint8_t m_PayloadSendBuffer[20];
uint8_t m_PayloadRecvBuffer[20];
uint8_t m_SendBuffer[50];
uint8_t m_ReceiveBuffer[80];

uint32_t          m_WorkerDeviceId = 0x63691402;
EStucChecksumType m_ChecksumType   = EStucChecksumType::CRC16;

uint16_t  m_ReceiveBufferWriteIndex = 0;
uint16_t  m_ReceiveBufferReadIndex  = 0;
bool      m_DataAvailable           = false;
bool      m_IsWorking               = false;
StucData  m_RequestData;

void setup ()
{
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

  m_pSTUC = new STUC (m_WorkerDeviceId, true, true, false, m_ChecksumType);

  m_RequestData.SetPayloadInfo (m_PayloadRecvBuffer,
                                sizeof (m_PayloadRecvBuffer));
}

void loop ()
{
  EResult result;

  if (Serial1.available ()
  &&  !m_IsWorking)
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

  if (m_DataAvailable
  &&  !m_IsWorking)
  {
    EStucMessageType  requestMessageType   = EStucMessageType::None;
    uint8_t           requestMessageLength = 0;

    // Analyse message in the received data
    result = m_pSTUC->AnalyseMessage (m_ReceiveBuffer,
                                      sizeof (m_ReceiveBuffer),
                                      m_ReceiveBufferReadIndex,
                                      m_RequestData,
                                      requestMessageType,
                                      requestMessageLength);
    Serial << F("STUC.AnalyseMessage() result=") << STUC::GetResultText (result) << endl;

    Serial << F("Message Type:        ") << (uint8_t)requestMessageType           << endl;
    Serial << F("Action:              ") << (uint8_t)m_RequestData.Action         << endl;
    Serial << F("Remote Device Id:    ") << _HEX8 (m_RequestData.RemoteDeviceId)  << endl;
    Serial << F("Message Id:          ") << m_RequestData.MessageId               << endl;
    Serial << F("Timestamp:           ") << m_RequestData.Timestamp               << endl;
    Serial << F("CommandId:           ") << m_RequestData.CommandId               << endl;
    Serial << F("Result:              ") << (uint8_t)m_RequestData.MessageResult  << endl;
    Serial << F("Payload Data Length: ") << m_RequestData.PayloadLength           << endl;
    Serial << F("Message Length:      ") << requestMessageLength                  << endl;

    Serial << F("PayloadRecvBuffer: bytes used = ") << m_RequestData.PayloadLength << endl;
    Memory_PrintLn (m_PayloadRecvBuffer, sizeof (m_PayloadRecvBuffer));

    if (result == EResult::SUCCESS)
    {
      RingBuffer_SetValueBackward (m_ReceiveBuffer,
                                   sizeof (m_ReceiveBuffer),
                                   m_ReceiveBufferReadIndex,
                                   requestMessageLength,
                                   c_BufferDefaultValue);
      Serial << F("ReceiveBuffer:") << endl;
      Memory_PrintLn (m_ReceiveBuffer, sizeof (m_ReceiveBuffer));

      m_IsWorking = true;
    }
    else
      m_DataAvailable = false;
  }

  if (m_IsWorking)
  {
    for (int index = 0; index < m_RequestData.PayloadLength; index++)
      m_PayloadSendBuffer[index] = m_PayloadRecvBuffer[m_RequestData.PayloadLength - index - 1];

    memset (m_PayloadRecvBuffer, c_BufferDefaultValue, m_RequestData.PayloadLength);
    Serial << F("PayloadRecvBuffer:") << endl;
    Memory_PrintLn (m_PayloadRecvBuffer, sizeof (m_PayloadRecvBuffer));
    Serial << F("PayloadSendBuffer:") << endl;
    Memory_PrintLn (m_PayloadSendBuffer, sizeof (m_PayloadSendBuffer));

    StucData replyData = StucData (m_RequestData.Action,
                                   m_RequestData.RemoteDeviceId,
                                   m_RequestData.MessageId,
                                   m_RequestData.Timestamp,
                                   m_RequestData.CommandId,
                                   EStucMessageResult::Success);
    replyData.SetPayloadInfo (m_PayloadSendBuffer, sizeof (m_PayloadSendBuffer), m_RequestData.PayloadLength);

    uint16_t replyMessageLength = 0;
    result = m_pSTUC->ComposeReply (replyData,
                                    m_SendBuffer,
                                    sizeof (m_SendBuffer),
                                    replyMessageLength);
    Serial << F("STUC.ComposeReply() result=") << STUC::GetResultText (result) << endl;

    Serial << F("SendBuffer: bytes used = ") << replyMessageLength << endl;
    Memory_PrintLn (m_SendBuffer, sizeof (m_SendBuffer));

    if (result == EResult::SUCCESS)
    {
      Serial1.write (m_SendBuffer, replyMessageLength);
      Serial1.flush ();
    }

    memset (m_PayloadSendBuffer, c_BufferDefaultValue, replyData.PayloadLength);
    memset (m_SendBuffer,        c_BufferDefaultValue, replyMessageLength);

    m_IsWorking = false;
  }

  if (!m_DataAvailable
  &&  !m_IsWorking)
  {
    Serial.println ("Idle.");
    delay (1000);
  }
}
