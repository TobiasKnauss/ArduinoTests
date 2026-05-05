//------------------------------------------------------------------------------
// Purpose of this test:
// - Declaration and assignment of integer variables (INT, LONG, etc.)
// - Mathematical operations with/without type cast
//------------------------------------------------------------------------------

#include <Streaming.h>

void setup()
{
  Serial.begin (9600);
}

void loop()
{
  int value_Int1 = 0;
  Serial << "--- value_Int1 ---" << endl;
  Serial << "after declaration:  " << value_Int1 << endl;
  value_Int1 = 1000;
  Serial << "after set to 1000:  " << value_Int1 << endl;
  value_Int1 = -789;
  Serial << "after set to -789:  " << value_Int1 << endl;
  // value_Int1 = 123456;    warning: overflow in implicit constant conversion
  // Serial << "after set to 123456:  " << value_Int1 << endl;

  Serial << "--- value_Long1 ---" << endl;
  long value_Long1 = 0;
  Serial << "after declaration:  " << value_Long1 << endl;
  value_Long1 = value_Int1 * 1000;
  Serial << "after  value_Int1 * 1000:  " << value_Long1 << endl;  // -> -2568
  value_Long1 = (long)value_Int1 * 1000L;
  Serial << "after  (long)value_Int1 * 1000:  " << value_Long1 << endl;  //  -> -789000
  Serial << endl;
  delay (10000);
}
