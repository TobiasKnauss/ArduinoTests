#include "EnumA.h"

#define CONCAT_IMPL( x, y ) x##y
#define MACRO_CONCAT( x, y ) CONCAT_IMPL( x, y )

//--------------------------------------------------------------------
void PrintEnumAText (Print& i_Printer, EnumA i_EnumA)
{
  switch (i_EnumA)
  {
  #define X(name,value) case EnumA::name: i_Printer.println (F(#name)); break;
  ENUMS_A1
  #undef X
  #define X(name) case EnumA::name: i_Printer.println (F(#name)); break;
  ENUMS_A2
  #undef X
  default: i_Printer.println (c_Text_Invalid); break;
  }
}
