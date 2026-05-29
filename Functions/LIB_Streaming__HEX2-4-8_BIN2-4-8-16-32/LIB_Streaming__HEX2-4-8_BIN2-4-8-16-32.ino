#include <Arduino.h>
#include <Streaming.h>

// #define _HEX(a)   _BASED<typeof(a)>(a, HEX)
// #define _HEX2(a)  _BASED<typeof(a)>(a, HEX2)
// #define _HEX4(a)  _BASED<typeof(a)>(a, HEX4)
// #define _HEX8(a)  _BASED<typeof(a)>(a, HEX8)
// #define _DEC(a)   _BASED<typeof(a)>(a, DEC)
// #define _OCT(a)   _BASED<typeof(a)>(a, OCT)
// #define _BIN(a)   _BASED<typeof(a)>(a, BIN)
// #define _BIN2(a)  _BASED<typeof(a)>(a, BIN2)
// #define _BIN4(a)  _BASED<typeof(a)>(a, BIN4)
// #define _BIN8(a)  _BASED<typeof(a)>(a, BIN8)
// #define _BIN16(a) _BASED<typeof(a)>(a, BIN16)
// #define _BIN32(a) _BASED<typeof(a)>(a, BIN32)

char space[] = "    ";
uint8_t  ui8a =          3;
uint8_t  ui8b =        123;
uint16_t ui16 =      54321;
uint32_t ui32 = 4030201099;
int8_t   i8   =       -123;
int16_t  i16  =        -29;
int32_t  i32  =  987654321;

void setup ()
{
  Serial.begin (9600);
  delay (2000);

  Serial << _WIDTH(ui8a, 12) << space << _PAD(6,'_') << _HEX2(ui8a) << space << _PAD(4,'_') << _HEX4(ui8a) << space << _HEX8(ui8a) << space << _PAD(30,'_') << _BIN2(ui8a) << space << _PAD(28,'_') << _BIN4(ui8a) << space << _PAD(24,'_') << _BIN8(ui8a) << space << _PAD(16,'_') << _BIN16(ui8a) << space << _BIN32 (ui8a) << endl;
  Serial << _WIDTH(ui8b, 12) << space << _PAD(6,'_') << _HEX2(ui8b) << space << _PAD(4,'_') << _HEX4(ui8b) << space << _HEX8(ui8b) << space << _PAD(25,'_') << _BIN2(ui8b) << space << _PAD(25,'_') << _BIN4(ui8b) << space << _PAD(24,'_') << _BIN8(ui8b) << space << _PAD(16,'_') << _BIN16(ui8b) << space << _BIN32 (ui8b) << endl;
  Serial << _WIDTH(ui16, 12) << space << _PAD(4,'_') << _HEX2(ui16) << space << _PAD(4,'_') << _HEX4(ui16) << space << _HEX8(ui16) << space << _PAD(16,'_') << _BIN2(ui16) << space << _PAD(16,'_') << _BIN4(ui16) << space << _PAD(16,'_') << _BIN8(ui16) << space << _PAD(16,'_') << _BIN16(ui16) << space << _BIN32 (ui16) << endl;
  Serial << _WIDTH(ui32, 12) << space << _PAD(0,'_') << _HEX2(ui32) << space << _PAD(0,'_') << _HEX4(ui32) << space << _HEX8(ui32) << space << _PAD( 0,'_') << _BIN2(ui32) << space << _PAD( 0,'_') << _BIN4(ui32) << space << _PAD( 0,'_') << _BIN8(ui32) << space << _PAD( 0,'_') << _BIN16(ui32) << space << _BIN32 (ui32) << endl;
  Serial << _WIDTH(i8  , 12) << space << _PAD(6,'_') << _HEX2(i8  ) << space << _PAD(4,'_') << _HEX4(i8  ) << space << _HEX8(i8  ) << space << _PAD(24,'_') << _BIN2(i8  ) << space << _PAD(24,'_') << _BIN4(i8  ) << space << _PAD(24,'_') << _BIN8(i8  ) << space << _PAD(16,'_') << _BIN16(i8  ) << space << _BIN32 (i8  ) << endl;
  Serial << _WIDTH(i16 , 12) << space << _PAD(4,'_') << _HEX2(i16 ) << space << _PAD(4,'_') << _HEX4(i16 ) << space << _HEX8(i16 ) << space << _PAD(16,'_') << _BIN2(i16 ) << space << _PAD(16,'_') << _BIN4(i16 ) << space << _PAD(16,'_') << _BIN8(i16 ) << space << _PAD(16,'_') << _BIN16(i16 ) << space << _BIN32 (i16 ) << endl;
  Serial << _WIDTH(i32 , 12) << space << _PAD(0,'_') << _HEX2(i32 ) << space << _PAD(0,'_') << _HEX4(i32 ) << space << _HEX8(i32 ) << space << _PAD( 2,'_') << _BIN2(i32 ) << space << _PAD( 2,'_') << _BIN4(i32 ) << space << _PAD( 2,'_') << _BIN8(i32 ) << space << _PAD( 2,'_') << _BIN16(i32 ) << space << _BIN32 (i32 ) << endl;
}

void loop ()
{
}
