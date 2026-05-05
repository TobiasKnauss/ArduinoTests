#include "EnumA.h"

//--------------------------------------------------------------------
const char* GetEnumAText (EnumA i_EnumA)
{
  if (i_EnumA < EnumA::Dummy_LastCommonResult)
    return c_EnumNames_A1[(uint16_t)i_EnumA];
  if (i_EnumA <= EnumA::Dummy_FirstCommonFailure)
    return c_Text_Invalid;
  if (i_EnumA < EnumA::Dummy_LastCommonFailure)
    return c_EnumNames_A2[(uint16_t)i_EnumA - (uint16_t)EnumA::Dummy_FirstCommonFailure - 1];
  if (i_EnumA <= EnumA::Dummy_FirstClassFailure)
    return c_Text_Invalid;
  return 0;
}
