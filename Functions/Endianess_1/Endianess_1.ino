// from https://en.wikipedia.org/wiki/Endianness:
//
// There are two principal ways a computer could number the individual bytes in a larger group,
// starting at either end. A big-endian system stores the most significant byte of a word at the
// smallest memory address and the least significant byte at the largest. A little-endian system,
// in contrast, stores the least-significant byte at the smallest address.
//
// Big-endianness is the dominant ordering in networking protocols, such as in the Internet protocol
// suite, where it is referred to as network order, transmitting the most significant byte first.
// Conversely, little-endianness is the dominant ordering for processor architectures (x86, most ARM
// implementations, base RISC-V implementations) and their associated memory.
//
// [...] the Atmel AVR, [...] and many other processors and processor families are also little-endian.
//
// When memory bytes are printed sequentially from left to right (e.g., in a hex dump), little-endian
// representation of integers has the significance increasing from right to left. In other words, it
// appears backwards when visualized, which can be counterintuitive.
//

uint8_t  m_UI8a  = 0x41;
uint16_t m_UI16a = 0x4142;
uint32_t m_UI32a = 0x41424344;

uint8_t  m_UI8b  = 0x12;
uint16_t m_UI16b = 0x1234;
uint32_t m_UI32b = 0x12345678;

char m_Text[] = "Hello!";

void PrintNUM (uint8_t* i_pUI8, uint8_t i_Size)
{
  for (uint8_t index = 0; index < i_Size; index++)
    Serial.print (*(i_pUI8 + index));
  Serial.println ();
}

void PrintHEX (uint8_t* i_pUI8, uint8_t i_Size)
{
  for (uint8_t index = 0; index < i_Size; index++)
    Serial.print (*(i_pUI8 + index), HEX2);
  Serial.println ();
}

void Write (uint8_t* i_pUI8, uint8_t i_Size)
{
  for (uint8_t index = 0; index < i_Size; index++)
    Serial.write (*(i_pUI8 + index));
  Serial.write (0x00);
}

void setup ()
{
  Serial.begin (9600);
  delay (2000);
  Serial.println ("Start");

  PrintNUM ((uint8_t*)&m_UI8a , sizeof (m_UI8a ));
  PrintNUM ((uint8_t*)&m_UI16a, sizeof (m_UI16a));
  PrintNUM ((uint8_t*)&m_UI32a, sizeof (m_UI32a));

  PrintNUM ((uint8_t*)&m_UI8b , sizeof (m_UI8b ));
  PrintNUM ((uint8_t*)&m_UI16b, sizeof (m_UI16b));
  PrintNUM ((uint8_t*)&m_UI32b, sizeof (m_UI32b));

  PrintNUM ((uint8_t*)m_Text, sizeof (m_Text));

  Serial.println ();

  PrintHEX ((uint8_t*)&m_UI8a , sizeof (m_UI8a ));
  PrintHEX ((uint8_t*)&m_UI16a, sizeof (m_UI16a));
  PrintHEX ((uint8_t*)&m_UI32a, sizeof (m_UI32a));

  PrintHEX ((uint8_t*)&m_UI8b , sizeof (m_UI8b ));
  PrintHEX ((uint8_t*)&m_UI16b, sizeof (m_UI16b));
  PrintHEX ((uint8_t*)&m_UI32b, sizeof (m_UI32b));

  PrintHEX ((uint8_t*)m_Text, sizeof (m_Text));

  Serial.println ();

  Write ((uint8_t*)&m_UI8a , sizeof (m_UI8a ));
  Write ((uint8_t*)&m_UI16a, sizeof (m_UI16a));
  Write ((uint8_t*)&m_UI32a, sizeof (m_UI32a));

  Write ((uint8_t*)&m_UI8b , sizeof (m_UI8b ));
  Write ((uint8_t*)&m_UI16b, sizeof (m_UI16b));
  Write ((uint8_t*)&m_UI32b, sizeof (m_UI32b));

  Write ((uint8_t*)&m_Text, sizeof (m_Text));
}

void loop ()
{
}
