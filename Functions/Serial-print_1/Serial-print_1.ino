void printHEX_m64_0 ()
{
  Serial.print("ASCII\t");
  Serial.print("i8:DEC\ti16:DEC\ti32:DEC\t");
  Serial.print("i8:X  \ti16:X  \ti32:X  \t\t");
  Serial.print("i8:X2 \ti16:X2 \ti32:X2 \t\t");
  Serial.print("i8:X4 \ti16:X4 \ti32:X4 \t\t");
  Serial.print("i8:X8\t\ti16:X8\t\ti32:X8\t\t");
  Serial.print("OCT");

  Serial.println();
  for (char c = -64; c < 0; c++)
  {
    int8_t  i8  = c;
    int16_t i16 = c;
    int32_t i32 = c;

    Serial.print(i8); // print as an ASCII-encoded decimal - same as "DEC"
    Serial.print("\t");

    Serial.print(i8, DEC);  Serial.print("\t"); Serial.print(i16, DEC);  Serial.print("\t"); Serial.print(i32, DEC);  Serial.print("\t"); // print as an ASCII-encoded decimal
    Serial.print(i8, HEX);  Serial.print("\t"); Serial.print(i16, HEX);  Serial.print("\t"); Serial.print(i32, HEX);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal
    Serial.print(i8, HEX2); Serial.print("\t"); Serial.print(i16, HEX2); Serial.print("\t"); Serial.print(i32, HEX2); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 2 digits
    Serial.print(i8, HEX4); Serial.print("\t"); Serial.print(i16, HEX4); Serial.print("\t"); Serial.print(i32, HEX4); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 4 digits
    Serial.print(i8, HEX8); Serial.print("\t"); Serial.print(i16, HEX8); Serial.print("\t"); Serial.print(i32, HEX8); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 8 digits
    Serial.print(i16, OCT); Serial.println(); // print as an ASCII-encoded octal

    delay(200);
  }
  Serial.println(); // prints another carriage return
}

void printHEX_0_96 ()
{
  Serial.print("ASCII\t");
  Serial.print("i8:DEC\ti16:DEC\ti32:DEC\t");
  Serial.print("i8:X  \ti16:X  \ti32:X  \t");
  Serial.print("i8:X2 \ti16:X2 \ti32:X2 \t");
  Serial.print("i8:X4 \ti16:X4 \ti32:X4 \t");
  Serial.print("i8:X8\t\ti16:X8\t\ti32:X8\t\t");
  Serial.print("OCT");

  Serial.println();
  for (char c = 0; c < 96; c++)
  {
    int8_t  i8  = c;
    int16_t i16 = c;
    int32_t i32 = c;

    Serial.print(i8); // print as an ASCII-encoded decimal - same as "DEC"
    if (c >= 32)
    { Serial.print (": "); Serial.print (c); } // print the ASCII character
    Serial.print("\t");

    Serial.print(i8, DEC);  Serial.print("\t"); Serial.print(i16, DEC);  Serial.print("\t"); Serial.print(i32, DEC);  Serial.print("\t"); // print as an ASCII-encoded decimal
    Serial.print(i8, HEX);  Serial.print("\t"); Serial.print(i16, HEX);  Serial.print("\t"); Serial.print(i32, HEX);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal
    Serial.print(i8, HEX2); Serial.print("\t"); Serial.print(i16, HEX2); Serial.print("\t"); Serial.print(i32, HEX2); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 2 digits
    Serial.print(i8, HEX4); Serial.print("\t"); Serial.print(i16, HEX4); Serial.print("\t"); Serial.print(i32, HEX4); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 4 digits
    Serial.print(i8, HEX8); Serial.print("\t"); Serial.print(i16, HEX8); Serial.print("\t"); Serial.print(i32, HEX8); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 8 digits
    Serial.print(i16, OCT); Serial.println(); // print as an ASCII-encoded octal

    delay(200);
  }
  Serial.println(); // prints another carriage return
}

void printBIN_m64_0 ()
{
  Serial.print("ASCII\t");
  Serial.print("i8:B  \t\ti16:B  \t\t\ti32:B  \t\t\t\t\t");
  Serial.print("i8:B2 \t\ti16:B2 \t\t\ti32:B2 \t\t\t\t\t");
  Serial.print("i8:B4 \t\ti16:B4 \t\t\ti32:B4 \t\t\t\t\t");
  Serial.print("i8:B8 \t\ti16:B8 \t\t\ti32:B8 \t\t\t\t\t");
  Serial.print("i8:B16\t\t\ti16:B16\t\t\ti32:B16\t\t\t\t\t");
  Serial.print("i8:B32\t\t\t\t\ti16:B32\t\t\t\t\ti32:B32");

  Serial.println();
  for (char c = -64; c < 0; c++)
  {
    int8_t  i8  = c;
    int16_t i16 = c;
    int32_t i32 = c;

    Serial.print(i8); // print as an ASCII-encoded decimal - same as "DEC"
    Serial.print("\t");

    Serial.print(i8, BIN);   Serial.print("\t"); Serial.print(i16, BIN);   Serial.print("\t"); Serial.print(i32, BIN);   Serial.print("\t"); // print as an ASCII-encoded hexadecimal
    Serial.print(i8, BIN2);  Serial.print("\t"); Serial.print(i16, BIN2);  Serial.print("\t"); Serial.print(i32, BIN2);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 2 digits
    Serial.print(i8, BIN4);  Serial.print("\t"); Serial.print(i16, BIN4);  Serial.print("\t"); Serial.print(i32, BIN4);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 4 digits
    Serial.print(i8, BIN8);  Serial.print("\t"); Serial.print(i16, BIN8);  Serial.print("\t"); Serial.print(i32, BIN8);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 8 digits
    Serial.print(i8, BIN16); Serial.print("\t"); Serial.print(i16, BIN16); Serial.print("\t"); Serial.print(i32, BIN16); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 16 digits
    Serial.print(i8, BIN32); Serial.print("\t"); Serial.print(i16, BIN32); Serial.print("\t"); Serial.print(i32, BIN32); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 32 digits
    Serial.println();

    delay(200);
  }
  Serial.println(); // prints another carriage return
}

void printBIN_0_96 ()
{
  Serial.print("ASCII\t");
  Serial.print("i8:B  \ti16:B  \ti32:B  \t");
  Serial.print("i8:B2 \ti16:B2 \ti32:B2 \t");
  Serial.print("i8:B4 \ti16:B4 \ti32:B4 \t");
  Serial.print("i8:B8 \t\ti16:B8 \t\ti32:B8 \t\t");
  Serial.print("i8:B16\t\t\ti16:B16\t\t\ti32:B16\t\t\t");
  Serial.print("i8:B32\t\t\t\t\ti16:B32\t\t\t\t\ti32:B32");

  Serial.println();
  for (char c = 0; c < 96; c++)
  {
    int8_t  i8  = c;
    int16_t i16 = c;
    int32_t i32 = c;

    Serial.print(i8); // print as an ASCII-encoded decimal - same as "DEC"
    if (c >= 32)
    { Serial.print (": "); Serial.print (c); } // print the ASCII character
    Serial.print("\t");

    Serial.print(i8, BIN);   Serial.print("\t"); Serial.print(i16, BIN);   Serial.print("\t"); Serial.print(i32, BIN);   Serial.print("\t"); // print as an ASCII-encoded hexadecimal
    Serial.print(i8, BIN2);  Serial.print("\t"); Serial.print(i16, BIN2);  Serial.print("\t"); Serial.print(i32, BIN2);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 2 digits
    Serial.print(i8, BIN4);  Serial.print("\t"); Serial.print(i16, BIN4);  Serial.print("\t"); Serial.print(i32, BIN4);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 4 digits
    Serial.print(i8, BIN8);  Serial.print("\t"); Serial.print(i16, BIN8);  Serial.print("\t"); Serial.print(i32, BIN8);  Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 8 digits
    Serial.print(i8, BIN16); Serial.print("\t"); Serial.print(i16, BIN16); Serial.print("\t"); Serial.print(i32, BIN16); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 16 digits
    Serial.print(i8, BIN32); Serial.print("\t"); Serial.print(i16, BIN32); Serial.print("\t"); Serial.print(i32, BIN32); Serial.print("\t"); // print as an ASCII-encoded hexadecimal with at least 32 digits
    Serial.println();

    delay(200);
  }
  Serial.println(); // prints another carriage return
}

void setup()
{
  Serial.begin(9600); // open the serial port at 9600 bps:
  delay (2000);
}

void loop ()
{
  printHEX_m64_0 ();
  printHEX_0_96 ();
  printBIN_m64_0 ();
  printBIN_0_96 ();
}