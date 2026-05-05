#include <Streaming.h>

void setup()
{
  Serial.begin (9600);

  for (int DO = 2; DO <= 19; DO++)
    pinMode (DO, OUTPUT);
}

void loop() 
{
  for (int DO = 2; DO <= 19; DO++)
  {
    digitalWrite (DO, HIGH);
  }
  delay (500);
  for (int DO = 2; DO <= 19; DO++)
  {
    digitalWrite (DO, LOW);
  }
  delay (500);

  for (int DO = 2; DO <= 19; DO++)
  {
    SetOutput (DO);
  }
}

void SetOutput (int i_DO)
{
  Serial << "DO " << i_DO << ":  ";
  digitalWrite (i_DO, HIGH);
  Serial << digitalRead (i_DO) << ", ";
  delay (500);
  digitalWrite (i_DO, LOW);
  Serial << digitalRead (i_DO) << endl;
  delay (500);
}
