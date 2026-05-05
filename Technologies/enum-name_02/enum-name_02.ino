#include "EnumA.h"
#include <Streaming.h>

void setup()
{
  Serial.begin (9600);
  Serial << "TEST" << endl;
  delay (100);
  PrintEnumAText (Serial, EnumA::None);
  PrintEnumAText (Serial, EnumA::SUCCESS);
  PrintEnumAText (Serial, EnumA::InProgress);
  PrintEnumAText (Serial, (EnumA)44);
  PrintEnumAText (Serial, EnumA::FAIL_Buffer_GetBytes);
  PrintEnumAText (Serial, EnumA::FAIL_Buffer_Overlap);
  PrintEnumAText (Serial, EnumA::FAIL_VeryVeryLongStupidUselessText_10);
  PrintEnumAText (Serial, EnumA::FAIL_VeryVeryLongStupidUselessText_20);
  PrintEnumAText (Serial, (EnumA)333);

  // Sketch uses 4042 bytes (12%) of program storage space. Maximum is 32256 bytes.
  // Global variables use 206 bytes (10%) of dynamic memory, leaving 1842 bytes for local variables. Maximum is 2048 bytes.
  for (uint16_t index = 0; index < 0x150; index++)
  {
    uint16_t value = index;
    Serial << _HEX4(value) << ": ";
    PrintEnumAText (Serial, (EnumA)value);
  }
}

void loop()
{
}
