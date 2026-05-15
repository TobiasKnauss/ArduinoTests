#include <Arduino.h>
#include <Streaming.h>

#include <IOHelper.h>

void setup ()
{
  Serial.begin (9600);

  delay (2000);

  for (int pin = 0; pin <= 0xFF; pin++)
  {
    Serial << "Pin " << pin << ":  Set pin mode OUTPUT.";
    pinMode (pin, OUTPUT);

    Serial << "write ON";
    digitalWrite (pin, true);
    Serial << ", read " << digitalRead (pin) << ".";
    delay (50);

    Serial << "  write OFF";
    digitalWrite (pin, false);
    Serial << ", read " << digitalRead (pin) << "." << endl;
    delay (50);
  }
}

void loop ()
{
}
