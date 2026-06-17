#include <Streaming.h>
#include <EEPROM.h>

void setup ()
{
  Serial.begin (9600);

  Serial << "EEPROM size:  " << EEPROM.length () << " bytes." << endl;
  Serial << "EEPROM content:";
  for (uint16_t index = 0; index < EEPROM.length (); index++)
  {
    if (index % 8 == 0)
      Serial << "  ";
    if (index % 32 == 0)
      Serial << endl << _HEX4 (index) <<  " :  ";
    Serial << _HEX2 (EEPROM[index]) << " ";
  }
}

void loop () 
{
}
