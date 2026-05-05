bool            m_StatusLED_On = false;
unsigned long   m_StatusLED_BlinkTimestamp;
Stream* m_Serial1 = &Serial;
Stream* m_Serial2 = &Serial1;

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

  requireBlink |= ForwardMessage (m_Serial1, m_Serial2);

  requireBlink |= ForwardMessage (m_Serial2, m_Serial1);

  if (millis () - m_StatusLED_BlinkTimestamp > 500
  ||  requireBlink)
    Blink ();

  delay (100);
}

bool ForwardMessage (Stream* i_pSerialSource,
                     Stream* i_pSerialDestination)
{
  if (i_pSerialSource->available () > 0)
  {
    byte character = i_pSerialSource->read();
    i_pSerialDestination->write (character);
    return true;
  }

  return false;
}

void Blink ()
{
  m_StatusLED_BlinkTimestamp = millis ();
  m_StatusLED_On = !m_StatusLED_On;
  digitalWrite (LED_BUILTIN, m_StatusLED_On);
}