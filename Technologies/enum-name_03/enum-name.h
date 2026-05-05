#ifndef enum_name_h
#define enum_name_h

#include <Arduino.h>

enum class Letter : uint8_t
{
  #define X(name) name,
  #include "letters.h"
  #undef X
};

#define X(name) const char str_##name[] PROGMEM = #name;
#include "letters.h"
#undef X

class LetterManager
{
  public:
    // 3. Ein Array von Zeigern im Flash, die auf die Flash-Strings zeigen
    static const char* const nameTable[] PROGMEM;

    static const __FlashStringHelper* getName(Letter l) {
      // Zugriff auf die Zeigertabelle im Flash
      return (const __FlashStringHelper*)pgm_read_ptr(&nameTable[(uint8_t)l]);
    }
};

#endif
