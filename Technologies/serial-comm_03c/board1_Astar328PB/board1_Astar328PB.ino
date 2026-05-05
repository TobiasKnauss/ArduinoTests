const char c_TerminatingChar = 0x03;
const byte c_BufferSize = 80;

bool            m_StatusLED_On = false;
unsigned long   m_StatusLED_BlinkTimestamp;
bool    m_WaitForTerminatingChar = false;
bool    m_Serial1TerminatingCharFound = false;
bool    m_Serial2TerminatingCharFound = false;
byte    m_Buffer1[c_BufferSize];
byte    m_Buffer2[c_BufferSize];
byte    m_Buffer1Index = 0;
byte    m_Buffer1Count = 0;
byte    m_Buffer2Index = 0;
byte    m_Buffer2Count = 0;
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

  requireBlink |= ForwardMessage (m_Serial1, m_Serial2, m_Buffer1, m_Buffer1Count, m_Buffer1Index, m_Serial1TerminatingCharFound);

  requireBlink |= ForwardMessage (m_Serial2, m_Serial1, m_Buffer2, m_Buffer2Count, m_Buffer2Index, m_Serial2TerminatingCharFound);

  if (millis () - m_StatusLED_BlinkTimestamp > 500
  ||  requireBlink)
    Blink ();

  delay (100);
}

bool ForwardMessage (Stream* i_pSerialSource,
                     Stream* i_pSerialDestination,
                     byte*   i_pBuffer,
                     byte&   io_BufferCount,
                     byte&   io_BufferIndex,
                     bool&   io_SerialTerminatingCharFound)
{
  if (i_pSerialSource->available () > 0)
  {
    byte character = i_pSerialSource->read ();

    if (character == c_TerminatingChar)
      io_SerialTerminatingCharFound = true;

    if (io_BufferCount < c_BufferSize)
    {
      io_BufferCount++;
      i_pBuffer[io_BufferIndex] = character;
      io_BufferIndex++;
      io_BufferIndex %= c_BufferSize;
    }
  }

  if (io_BufferCount > 0
  &&  io_SerialTerminatingCharFound)
  {
    byte index = io_BufferIndex - io_BufferCount;
    if (io_BufferCount > io_BufferIndex)
      index += c_BufferSize;
    i_pSerialDestination->write (i_pBuffer[index]);
    io_BufferCount--;
    if (io_BufferCount == 0)
      io_SerialTerminatingCharFound = false;
  }

  return true;
}

void Blink ()
{
  m_StatusLED_BlinkTimestamp = millis ();
  m_StatusLED_On = !m_StatusLED_On;
  digitalWrite (LED_BUILTIN, m_StatusLED_On);
}