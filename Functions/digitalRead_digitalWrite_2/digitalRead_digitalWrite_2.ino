#include <Arduino.h>
#include <Streaming.h>

#include <IOHelper.h>

void setup ()
{
  Serial.begin (9600);

  delay (2000);

  TestPinMode (INPUT);
  TestPinMode (INPUT_PULLUP);
  TestPinMode (OUTPUT);
  delay (2000);

  for (int value = 0; value <= 0xFF; value++)
  {
    TestPinMode (value);
    delay (50);
  }
  delay (2000);

  pinMode (LED_BUILTIN, OUTPUT);

  for (int value = 0; value <= 0xFF; value++)
  {
    Serial << "write " << value;
    digitalWrite (LED_BUILTIN, value);
    Serial << ", read " << digitalRead (LED_BUILTIN) << ".";
    delay (50);

    Serial << "  write " << false;
    digitalWrite (LED_BUILTIN, false);
    Serial << ", read " << digitalRead (LED_BUILTIN) << "." << endl;
    delay (50);
  }
}

void loop ()
{
}

void TestPinMode (uint8_t i_Value)
{
  Serial << "Set pin mode " << i_Value << " (" << getPinModeName (i_Value) << ").";
  pinMode (LED_BUILTIN, i_Value);
  uint8_t currentPinMode = getPinMode (LED_BUILTIN);
  Serial << "  Get pin mode " << currentPinMode << " (" << getPinModeName (currentPinMode) << ")." << endl;
}


