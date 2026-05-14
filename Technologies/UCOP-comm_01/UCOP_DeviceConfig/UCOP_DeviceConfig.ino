#include <Streaming.h>

#include <UCOP.h>

const bool     c_WriteConfig = false;  // <--- Set this flag to TRUE if the config has to be changed.
const uint16_t c_EepromOffset = 0;

const bool                m_DeviceIdsUsed = true;
const bool                m_MessageIdUsed = true;
const bool                m_TimestampUsed = false;
const uint32_t            m_DeviceId      = 0x63691401;
const UCOP::EChecksumType m_ChecksumType  = UCOP::EChecksumType::CRC16;

void setup ()
{
  Serial.begin (9600);
  delay (2000);

  EResult result;
  UCOP ucop = UCOP (c_EepromOffset, result);
  Serial << "UCOP ctor, EEPROM READ, Result: " << (int)result << " = " << UCOP::GetResultText (result) << endl;
  ucop.PrintConfig ();

  if (!c_WriteConfig)
    return;

  ucop = UCOP (m_DeviceIdsUsed,
               m_MessageIdUsed,
               m_TimestampUsed,
               m_DeviceId,
               m_ChecksumType,
               result);
  Serial << "UCOP ctor, new config, Result: " << (int)result << " = " << UCOP::GetResultText (result) << endl;
  ucop.PrintConfig ();

  result = ucop.WriteConfigToEEPROM (c_EepromOffset);
  Serial << "UCOP WriteConfigToEEPROM, EEPROM WRITE, Result: " << (int)result << " = " << UCOP::GetResultText (result) << endl;

  ucop = UCOP (c_EepromOffset, result);
  Serial << "UCOP ctor, EEPROM READ, Result: " << (int)result << " = " << UCOP::GetResultText (result) << endl;
  ucop.PrintConfig ();
}

void loop ()
{
}
