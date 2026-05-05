bool            m_StatusLED_On = false;
unsigned long   m_StatusLED_BlinkTimestamp;

void setup()
{
  pinMode (LED_BUILTIN, OUTPUT);

  Serial.begin (9600);
  Serial1.begin (9600);

  m_StatusLED_BlinkTimestamp = millis ();
}

void loop()
{
  bool requireBlink = false;

  if (Serial.available () > 0)
  {
    byte character = Serial.read();
    Serial1.write (character);
    requireBlink = true;
  }
  
  if (Serial1.available () > 0)
  {
    byte character = Serial1.read();
    Serial.write (character);
    requireBlink = true;
  }

  if (millis () - m_StatusLED_BlinkTimestamp > 500
  ||  requireBlink)
    Blink ();

  delay (100);
}

void Blink ()
{
  m_StatusLED_BlinkTimestamp = millis ();
  m_StatusLED_On = !m_StatusLED_On;
  digitalWrite (LED_BUILTIN, m_StatusLED_On);
}