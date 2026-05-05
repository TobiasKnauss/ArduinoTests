#include <Arduino.h>
#include <FastCRC.h>

FastCRC8  m_Crc8;
FastCRC16 m_Crc16;
FastCRC32 m_Crc32;

uint8_t m_Buffer[20];

void setup ()
{
  for (uint8_t index = 0; index < sizeof (m_Buffer); index++)
    m_Buffer [index] = (index + 1) * 10;

  uint8_t crc8_1 = m_Crc8.maxim (m_Buffer, 20);

                   m_Crc8.maxim (m_Buffer, 10);
  uint8_t crc8_2 = m_Crc8.maxim_upd (m_Buffer + 10, 10);

  uint8_t crc16_1 = m_Crc16.modbus (m_Buffer, 20);

                    m_Crc16.modbus (m_Buffer, 9);
  uint8_t crc16_2 = m_Crc16.modbus_upd (m_Buffer + 9, 11);

  uint8_t crc32_1 = m_Crc32.crc32 (m_Buffer, 20);

                    m_Crc32.crc32 (m_Buffer, 12);
  uint8_t crc32_2 = m_Crc32.crc32_upd (m_Buffer + 12, 8);

  Serial.begin (9600);
  Serial.println (crc8_1);
  Serial.println (crc8_2);
  Serial.println (crc16_1);
  Serial.println (crc16_2);
  Serial.println (crc32_1);
  Serial.println (crc32_2);
}

void loop()
{

}
