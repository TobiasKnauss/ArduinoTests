#include "EnumA.h"
#include <Streaming.h>

void setup()
{
  Serial.begin (9600);

  Serial.println (GetEnumAText (EnumA::None));
  Serial.println (GetEnumAText (EnumA::SUCCESS));
  Serial.println (GetEnumAText (EnumA::InProgress));
  Serial.println (GetEnumAText ((EnumA)44));
  Serial.println (GetEnumAText (EnumA::FAIL_Buffer_GetBytes));
  Serial.println (GetEnumAText (EnumA::FAIL_Buffer_Overlap));
  Serial.println (GetEnumAText (EnumA::FAIL_VeryVeryLongStupidUselessText_10));
  Serial.println (GetEnumAText (EnumA::FAIL_VeryVeryLongStupidUselessText_20));
  Serial.println (GetEnumAText ((EnumA)333));

  // Make some weird calculations to create "value" to avoid compiler optimizations.
  //   Global variables use 1548 bytes (75%) of dynamic memory, leaving 500 bytes for local variables. Maximum is 2048 bytes.
  // If value was assigned a fixed value, the compiler would remove all unneeded enum texts:
  //   Global variables use 380 bytes (18%) of dynamic memory, leaving 1668 bytes for local variables. Maximum is 2048 bytes.
  uint16_t data[2];
  data[0] = 0x120;
  data[1] = 0x124;
  for (uint8_t index = 0; index < 5; index++)
  {
    // variant A:
    uint16_t value = data[*((uint16_t*)index) > 0x7FFF ? 1 : 0];
    // variant B:
    //uint16_t value = 0x120;
    
    Serial << _HEX4(value) << ": " << GetEnumAText ((EnumA)value) << endl;
  }

}

void loop()
{
}
