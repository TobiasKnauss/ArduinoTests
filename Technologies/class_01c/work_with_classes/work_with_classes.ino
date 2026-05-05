#include "src/class_A/class_A.h"

ClassA m_ObjectA;

void setup ()
{
  // put your setup code here, to run once:
  Serial.begin (9600);

  m_ObjectA.Set_Int1 (10);
}

void loop ()
{
  int var1 = m_ObjectA.Get_Int1 ();
  Serial.println (var1);
  m_ObjectA.Set_Int1 (var1 + 2);
  delay (500);
}
