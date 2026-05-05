//------------------------------------------------------------------------------
// Purpose of this test:
// - Functionality of function 'pow' (mathematical operation "power")
//------------------------------------------------------------------------------

#include <Streaming.h>

void setup()
{
  Serial.begin (9600);
}

void loop()
{
  // on Arduino Uno, double = 4 bytes (== float)!
  volatile int iExp = -4;
  float f102 = pow (10,iExp);
  Serial << f102 << " " << String(f102, 10) << endl;
  Serial << pow(10,iExp) << endl;
  for (int ixCnt = 0; ixCnt < 4; ixCnt++)
    Serial << _HEX(*((byte*)&f102 + ixCnt)) << " ";
  Serial << endl;

  float f = 10;
  byte* pbf = (byte*)(&f);
  for (int ixCnt = 0; ixCnt < 4; ixCnt++)
    Serial << (long)(pbf + ixCnt) << " " << _HEX(*(pbf + ixCnt)) << endl;
  
  delay (10000);
}
