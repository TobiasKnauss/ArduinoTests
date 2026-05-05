class ClassA
{
private:
  int m_Int1 = 1;
  
public:
  int Get_Int1 ()
  {
    return m_Int1;
  }

  void Set_Int1 (int i_Int1)
  {
    m_Int1 = i_Int1;
  }
};

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
