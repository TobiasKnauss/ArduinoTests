class CTest1
{
public:
  enum EResult
  {
  #include "CommonResults.h"
  };
};

class CTest2
{
public:
  enum EResult
  {
  #include "CommonResults.h"
  };
};

void setup()
{
  Serial.begin (9600);
}

void loop() 
{
  CTest1::EResult res1a = CTest1::EResult::SUCCESS;
  CTest1::EResult res1b = res1a;
  CTest2::EResult res2a = CTest2::EResult::SUCCESS;
  CTest2::EResult res2b = res2a;
  // res1b = res2a;   --> error: cannot convert 'CTest2::EResult' to 'CTest1::EResult' in assignment
  // res2b = res1a;   --> error: cannot convert 'CTest1::EResult' to 'CTest2::EResult' in assignment
  
  Serial.println (res1a);
  Serial.println (res2a);
  delay (1000);
}
