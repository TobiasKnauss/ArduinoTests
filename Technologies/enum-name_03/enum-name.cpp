#include "enum-name.h"

// Definition der Zeigertabelle im Flash
const char* const LetterManager::nameTable[] PROGMEM = {
  #define X(name) str_##name,
  #include "letters.h"
  #undef X
};

