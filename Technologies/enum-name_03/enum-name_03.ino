// KI-generiert von Google, siehe beiliegendes PDF.
// Überarbeitet und aufgeteilt in .ino, .h und .cpp

#include "enum-name.h"

void setup ()
{
  Serial.begin(9600);
  
  Letter myLetter = Letter::E;
  
  Serial.print(F("Enum Name aus PROGMEM: "));
  // getName gibt einen __FlashStringHelper* zurück, den Serial.print versteht
  Serial.println(LetterManager::getName(myLetter)); 
}

void loop ()
{

}