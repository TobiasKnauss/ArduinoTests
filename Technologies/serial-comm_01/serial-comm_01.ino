const int c_DataRateIndex = 2;
const int c_DataWordConfigIndex = 1;
const int c_CommMode = 2;
const unsigned short c_DelayForSerialWrite = 20;

void setup()
{
  pinMode (LED_BUILTIN, OUTPUT);

  unsigned long dataRate = 0;
  switch (c_DataRateIndex)
  {
  case  1: dataRate =    300; break;
  case  2: dataRate =   9600; break;
  case  3: dataRate = 115200; break;
  default: dataRate =   9600;
  }

  byte dataWordConfig = 0;
  switch (c_DataWordConfigIndex)
  {
  case  1: dataWordConfig = SERIAL_8N1; break;
  case  2: dataWordConfig = SERIAL_8E1; break;
  default: dataWordConfig = SERIAL_8N1;
  }

  delay (1000);
  Serial.begin (dataRate, dataWordConfig);
}

void loop ()
{
  switch (c_CommMode)
  {
  case 1: comm1 (); break;
  case 2: comm2 (); break;
  }
}

void comm1 ()
{
  Serial.write ("AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH");
  delay (c_DelayForSerialWrite);
}

void comm2 ()
{
  Serial.print (Serial.availableForWrite());
  Serial.write ("AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH");
  delay (c_DelayForSerialWrite);
  Serial.print (Serial.availableForWrite());
  Serial.write ("AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH");
  delay (c_DelayForSerialWrite);
  Serial.print (Serial.availableForWrite());
  Serial.write ("AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH");
  delay (c_DelayForSerialWrite);
  Serial.print (Serial.availableForWrite());
  Serial.write ("AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHH");
  delay (c_DelayForSerialWrite);
  Serial.print (Serial.availableForWrite());
  Serial.flush ();
  Serial.print (Serial.availableForWrite());
  delay (2000);

}