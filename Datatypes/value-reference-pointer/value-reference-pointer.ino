#include <Arduino.h>
#include <Streaming.h>

int Add1_ValArg (int i_Value)
{
  return i_Value + 1;
}

int Add1_RefArg (int& i_rValue)
{
  return i_rValue + 1;
}

int Add1_PtrArg (int* i_pValue)
{
  return *i_pValue + 1;
}

void setup ()
{
  Serial.begin (9600);
  delay (2000);
  int value1 = 9;
  int* pvalue1 = &value1;

  Serial << "Add1_ValArg(): " << Add1_ValArg (value1) << endl;   // OK
  Serial << "Add1_ValArg(): " << Add1_ValArg (pvalue1) << endl;  // nonsense!   warning: invalid conversion from 'int*' to 'int'
  Serial << "Add1_RefArg(): " << Add1_RefArg (value1) << endl;   // OK
  //Serial << "Add1_RefArg(): " << Add1_RefArg (pvalue1) << endl;   does not compile
  Serial << "Add1_RefArg(): " << Add1_RefArg (*pvalue1) << endl; // OK
  Serial << "Add1_PtrARg(): " << Add1_PtrArg (value1) << endl;   // nonsense!   warning: invalid conversion from 'int' to 'int*'
  Serial << "Add1_PtrARg(): " << Add1_PtrArg (pvalue1) << endl;  // OK
}

void loop ()
{
}
