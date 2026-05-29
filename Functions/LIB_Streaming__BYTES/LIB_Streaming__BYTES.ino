#include <Arduino.h>
#include <Streaming.h>

char arrows1[] = " >>>";
char arrows2[] = "<<<";

char text_null[0];
char text_1[1]    = {'X'};
char text_1_sz[]  = "X";
char text_5a[5]   = {'H','e','l','l','o'};
char text_5a_sz[] = "Hello";
char text_5b[5]   = "ABC";
char text_5b_sz[] = "ABC";
char text_32a[32] = "abcdefghijklmnopqrstuvwxyz";
char text_32b[32] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6'};

void setup ()
{
  Serial.begin (9600);
  delay (2000);

  Serial << F("text_null:   len=") << sizeof (text_null  ) << arrows1 << _BYTES (text_null  , sizeof (text_null  )) << arrows2 << arrows1 << _BYTES (text_null  , strnlen (text_null  , sizeof (text_null ))) <<  arrows2 << endl;
  Serial << F("text_1:      len=") << sizeof (text_1     ) << arrows1 << _BYTES (text_1     , sizeof (text_1     )) << arrows2 << arrows1 << _BYTES (text_1     , strnlen (text_1     , sizeof (text_1    ))) <<  arrows2 << endl;
  Serial << F("text_1_sz:   len=") << sizeof (text_1_sz  ) << arrows1 << _BYTES (text_1_sz  , sizeof (text_1_sz  )) << arrows2 << arrows1 << _BYTES (text_1_sz  , strnlen (text_1_sz  , sizeof (text_1_sz ))) <<  arrows2 << endl;
  Serial << F("text_5a:     len=") << sizeof (text_5a    ) << arrows1 << _BYTES (text_5a    , sizeof (text_5a    )) << arrows2 << arrows1 << _BYTES (text_5a    , strnlen (text_5a    , sizeof (text_5a   ))) <<  arrows2 << endl;
  Serial << F("text_5a_sz:  len=") << sizeof (text_5a_sz ) << arrows1 << _BYTES (text_5a_sz , sizeof (text_5a_sz )) << arrows2 << arrows1 << _BYTES (text_5a_sz , strnlen (text_5a_sz , sizeof (text_5a_sz))) <<  arrows2 << endl;
  Serial << F("text_5b:     len=") << sizeof (text_5b    ) << arrows1 << _BYTES (text_5b    , sizeof (text_5b    )) << arrows2 << arrows1 << _BYTES (text_5b    , strnlen (text_5b    , sizeof (text_5b   ))) <<  arrows2 << endl;
  Serial << F("text_5b_sz:  len=") << sizeof (text_5b_sz ) << arrows1 << _BYTES (text_5b_sz , sizeof (text_5b_sz )) << arrows2 << arrows1 << _BYTES (text_5b_sz , strnlen (text_5b_sz , sizeof (text_5b_sz))) <<  arrows2 << endl;
  Serial << F("text_32a:    len=") << sizeof (text_32a   ) << arrows1 << _BYTES (text_32a   , sizeof (text_32a   )) << arrows2 << arrows1 << _BYTES (text_32a   , strnlen (text_32a   , sizeof (text_32a  ))) <<  arrows2 << endl;
  Serial << F("text_32b:    len=") << sizeof (text_32b   ) << arrows1 << _BYTES (text_32b   , sizeof (text_32b   )) << arrows2 << arrows1 << _BYTES (text_32b   , strnlen (text_32b   , sizeof (text_32b  ))) <<  arrows2 << endl;

  Serial << F("text_32a,  offset = 5 : ") << arrows1 << _BYTES (text_32a + 5, sizeof (text_32a   ) - 5) << arrows2 << arrows1 << _BYTES (text_32a + 5, strnlen (text_32a, sizeof (text_32a  )) - 5) <<  arrows2 << endl;
  Serial << F("text_32b,  offset = 5 : ") << arrows1 << _BYTES (text_32b + 5, sizeof (text_32b   ) - 5) << arrows2 << arrows1 << _BYTES (text_32b + 5, strnlen (text_32b, sizeof (text_32b  )) - 5) <<  arrows2 << endl;
}

void loop ()
{
}
