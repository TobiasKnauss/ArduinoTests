// source: https://docs.arduino.cc/language-reference/en/functions/communication/serial/print/

/*
  Uses a for loop to print numbers in various formats.
*/
void setup()
{
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop()
{
  // print labels
  Serial.print("NO FORMAT"); // prints a label 
  Serial.print("\t"); // prints a tab
  Serial.print("DEC"); 
  Serial.print("\t");
  Serial.print("HEX"); 
  Serial.print("\t");
  Serial.print("HEX2"); 
  Serial.print("\t");
  Serial.print("HEX4"); 
  Serial.print("\t");
  Serial.print("HEX8"); 
  Serial.print("\t\t");
  Serial.print("OCT"); 
  Serial.print("\t");
  Serial.print("BIN");
  Serial.print("\t");
  Serial.print("BIN2");
  Serial.print("\t");
  Serial.print("BIN4");
  Serial.print("\t");
  Serial.print("BIN8");
  Serial.print("\t\t");
  Serial.print("BIN16");
  Serial.print("\t\t\t");
  Serial.print("BIN32");
  Serial.println(); // carriage return after the last label
  for (int x = 0; x < 64; x++)
  { // only part of the ASCII chart, change to suit
    // print it out in many formats:
    Serial.print(x); // print as an ASCII-encoded decimal - same as "DEC" 
    Serial.print("\t\t"); // prints two tabs to accomodate the label length
    Serial.print(x, DEC); // print as an ASCII-encoded decimal 
    Serial.print("\t"); // prints a tab
    Serial.print(x, HEX); // print as an ASCII-encoded hexadecimal 
    Serial.print("\t"); // prints a tab
    Serial.print(x, HEX2); // print as an ASCII-encoded hexadecimal 
    Serial.print("\t"); // prints a tab
    Serial.print(x, HEX4); // print as an ASCII-encoded hexadecimal 
    Serial.print("\t"); // prints a tab
    Serial.print(x, HEX8); // print as an ASCII-encoded hexadecimal 
    Serial.print("\t"); // prints a tab
    Serial.print(x, OCT); // print as an ASCII-encoded octal 
    Serial.print("\t"); // prints a tab
    Serial.print(x, BIN); // print as an ASCII-encoded binary 
    Serial.print("\t"); // prints a tab
    Serial.print(x, BIN2); // print as an ASCII-encoded binary 
    Serial.print("\t"); // prints a tab
    Serial.print(x, BIN4); // print as an ASCII-encoded binary 
    Serial.print("\t"); // prints a tab
    Serial.print(x, BIN8); // print as an ASCII-encoded binary 
    Serial.print("\t"); // prints a tab
    Serial.print(x, BIN16); // print as an ASCII-encoded binary 
    Serial.print("\t"); // prints a tab
    Serial.println(x, BIN32); // print as an ASCII-encoded binary 
    // then adds the carriage return with "println"
    delay(200); // delay 200 milliseconds
  }
  Serial.println(); // prints another carriage return
}