#include <Arduino.h>
#include <Streaming.h>
#include "STUCv1.h"

STUCv1* m_pStucV1;

byte m_PayloadDataBufferLength = 20;
byte m_SendBufferLength        = 80;
byte m_ReceiveBufferLength     = 80;
byte m_PayloadDataBuffer    [20];
byte m_SendBuffer           [80];
byte m_ReceiveBuffer        [80];
byte m_PayloadDataRecvBuffer[20];

void setup ()
{
  memset (m_PayloadDataBuffer, 0xEE, m_PayloadDataBufferLength);
  memset (m_SendBuffer       , 0xFF, m_SendBufferLength);
  memset (m_PayloadDataRecvBuffer       , 0xFF, m_PayloadDataBufferLength);

  Serial.begin(9600);
  Serial << "#1:" << STUCv1::GetResultText (STUCv1::EResult::FAIL_Message_ResultWrong) << endl;

  byte recvPayloadDataLength = 0;

  EResult result = m_pStucV1->AnalyseMessage (m_ReceiveBuffer, m_ReceiveBufferLength);
  Serial << "#2:" << STUCv1::GetResultText ((STUCv1::EResult)result);
}

void loop ()
{
}
