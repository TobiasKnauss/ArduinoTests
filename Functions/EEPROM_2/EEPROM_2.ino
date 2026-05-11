#include <Streaming.h>
#include <EEPROM.h>

const bool      c_ValueB_F  = false;
const bool      c_ValueB_T  = true;
const uint8_t   c_ValueUI8  = 0x99;
const uint16_t  c_ValueUI16 = 0x1234;
const uint32_t  c_ValueUI32 = 0x87654321;
const int8_t    c_ValueI8   = -123;
const int16_t   c_ValueI16  = -24680;
const int32_t   c_ValueI32  = 4000000000;
const float     c_ValueF_1  = 678.9123;
const float     c_ValueF_2  = NAN;  // 0x7fc00000

const uint16_t  c_EepromOffset = 0;
const uint16_t  c_EepromShowLength = 0x40;

void setup ()
{
  Serial.begin (9600);
  delay (2000);

  Serial << "EEPROM size:  " << EEPROM.length () << " bytes." << endl;
  for (uint16_t index = 0; index < EEPROM.length (); index++)
    EEPROM.update (index, 0xFF);

  ShowEepromContent (c_EepromShowLength);

  uint16_t eepromAddress = c_EepromOffset;

  uint16_t eepromStartAddress = eepromAddress;
  for (uint8_t index = 0; index < sizeof (c_ValueB_F); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueB_F + index));
  for (uint8_t index = 0; index < sizeof (c_ValueB_T); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueB_T + index));
  Serial << "2x BOOL (" << c_ValueB_F << ", " << c_ValueB_T << ") via byte-write: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;
  
  eepromStartAddress = eepromAddress;
  EEPROM.put (eepromAddress, c_ValueB_F); eepromAddress += sizeof (c_ValueB_F);
  EEPROM.put (eepromAddress, c_ValueB_T); eepromAddress += sizeof (c_ValueB_T);
  Serial << "2x BOOL (" << c_ValueB_F << ", " << c_ValueB_T << ") via put: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;

  ShowEepromContent (c_EepromShowLength);

  eepromStartAddress = eepromAddress;
  for (uint8_t index = 0; index < sizeof (c_ValueUI8); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueUI8 + index));
  for (uint8_t index = 0; index < sizeof (c_ValueUI16); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueUI16 + index));
  for (uint8_t index = 0; index < sizeof (c_ValueUI32); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueUI32 + index));
  Serial << "UInt8 (" << c_ValueUI8 << " = 0x" << _HEX2(c_ValueUI8) << "), UInt16 (" << c_ValueUI16 << " = 0x" << _HEX4(c_ValueUI16) << "), UInt32 (" << c_ValueUI32 << " = 0x" << _HEX8(c_ValueUI32) << ") via byte-write: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;

  eepromStartAddress = eepromAddress;
  EEPROM.put (eepromAddress, c_ValueUI8);  eepromAddress += sizeof (c_ValueUI8);
  EEPROM.put (eepromAddress, c_ValueUI16); eepromAddress += sizeof (c_ValueUI16);
  EEPROM.put (eepromAddress, c_ValueUI32); eepromAddress += sizeof (c_ValueUI32);
  Serial << "UInt8 (" << c_ValueUI8 << " = 0x" << _HEX2(c_ValueUI8) << "), UInt16 (" << c_ValueUI16 << " = 0x" << _HEX4(c_ValueUI16) << "), UInt32 (" << c_ValueUI32 << " = 0x" << _HEX8(c_ValueUI32) << ") via put: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;

  ShowEepromContent (c_EepromShowLength);

  eepromStartAddress = eepromAddress;
  for (uint8_t index = 0; index < sizeof (c_ValueI8); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueI8 + index));
  for (uint8_t index = 0; index < sizeof (c_ValueI16); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueI16 + index));
  for (uint8_t index = 0; index < sizeof (c_ValueI32); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueI32 + index));
  Serial << "Int8 (" << c_ValueI8 << " = 0x" << _HEX2(c_ValueI8) << "), Int16 (" << c_ValueI16 << " = 0x" << _HEX4(c_ValueI16) << "), Int32 (" << c_ValueI32 << " = 0x" << _HEX8(c_ValueI32) << ") via byte-write: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;

  eepromStartAddress = eepromAddress;
  EEPROM.put (eepromAddress, c_ValueI8);  eepromAddress += sizeof (c_ValueI8);
  EEPROM.put (eepromAddress, c_ValueI16); eepromAddress += sizeof (c_ValueI16);
  EEPROM.put (eepromAddress, c_ValueI32); eepromAddress += sizeof (c_ValueI32);
  Serial << "Int8 (" << c_ValueI8 << " = 0x" << _HEX2(c_ValueI8) << "), Int16 (" << c_ValueI16 << " = 0x" << _HEX4(c_ValueI16) << "), Int32 (" << c_ValueI32 << " = 0x" << _HEX8(c_ValueI32) << ") via put: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;

  ShowEepromContent (c_EepromShowLength);

  eepromStartAddress = eepromAddress;
  for (uint8_t index = 0; index < sizeof (c_ValueF_1); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueF_1 + index));
  for (uint8_t index = 0; index < sizeof (c_ValueF_2); index++)
    EEPROM.write (eepromAddress++, *((uint8_t*)&c_ValueF_2 + index));
  Serial << "2x Float (" << c_ValueF_1 << ", " << c_ValueF_2 << ") via byte-write: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;

  eepromStartAddress = eepromAddress;
  EEPROM.put (eepromAddress, c_ValueF_1); eepromAddress += sizeof (c_ValueF_1);
  EEPROM.put (eepromAddress, c_ValueF_2); eepromAddress += sizeof (c_ValueF_2);
  Serial << "2x Float (" << c_ValueF_1 << ", " << c_ValueF_2 << ") via put: " << (eepromAddress - eepromStartAddress) << " bytes." << endl;

  ShowEepromContent (c_EepromShowLength);
}

void loop () 
{
}

void ShowEepromContent (uint16_t i_Length)
{
  Serial << "EEPROM content (0.." << (i_Length - 1) << "):";
  for (uint16_t index = 0; index < i_Length; index++)
  {
    if (index % 8 == 0)
      Serial << "  ";
    if (index % 32 == 0)
      Serial << endl << _HEX4 (index) <<  " :  ";
    Serial << _HEX2 (EEPROM[index]) << " ";
  }
  Serial << endl;
}
