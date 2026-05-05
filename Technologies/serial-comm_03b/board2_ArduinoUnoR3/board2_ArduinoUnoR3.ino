bool            m_StatusLED_On = false;
unsigned long   m_StatusLED_BlinkTimestamp;

void setup()
{
  pinMode (LED_BUILTIN, OUTPUT);

  Serial.begin (9600);

  m_StatusLED_BlinkTimestamp = millis ();
}

void loop()
{
  bool requireBlink = false;

  if (Serial.available () > 0)
  {
    byte character = Serial.read();
    if (character >= 0x20 && character < 0x7F)
      character++;
    Serial.write (character);
    requireBlink = true;
  }

  if (millis () - m_StatusLED_BlinkTimestamp > 500
  ||  requireBlink)
    Blink ();

  delay (20);
}

void Blink ()
{
  m_StatusLED_BlinkTimestamp = millis ();
  m_StatusLED_On = !m_StatusLED_On;
  digitalWrite (LED_BUILTIN, m_StatusLED_On);
}