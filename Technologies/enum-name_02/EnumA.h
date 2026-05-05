#ifndef EnumA_h
#define EnumA_h

#define CONCAT_IMPL( x, y ) x##y
#define MACRO_CONCAT( x, y ) CONCAT_IMPL( x, y )

#include <Arduino.h>

#define ENUMS_A1 \
X(None       , 0) \
X(SUCCESS    , 1) \
X(InProgress , 2) \
X(UserAbort  , 3)

#define ENUMS_A2 \
X(FAIL_Buffer_GetBytes                  ) \
X(FAIL_Buffer_GetValue                  ) \
X(FAIL_Buffer_IndexOutsideRange         ) \
X(FAIL_Buffer_MessageNotFound           ) \
X(FAIL_Buffer_Overlap                   ) \
X(FAIL_Buffer_TooSmall                  ) \
\
X(FAIL_Operation_Failed                 ) \
X(FAIL_Operation_StepInvalid            ) \
X(FAIL_Operation_TimeLimitExceeded      ) \
\
X(FAIL_Pointer_IsZero                   ) \
X(FAIL_Pointer_IsOutsideRange           ) \
\
X(FAIL_Value_AboveLimit                 ) \
X(FAIL_Value_BelowLimit                 ) \
X(FAIL_Value_Invalid                    ) \
X(FAIL_Value_Missing                    ) \
X(FAIL_Value_OutOfRange                 ) \
X(FAIL_Value_Wrong                      ) \
\
X(FAIL_VeryVeryLongStupidUselessText_01 ) \
X(FAIL_VeryVeryLongStupidUselessText_02 ) \
X(FAIL_VeryVeryLongStupidUselessText_03 ) \
X(FAIL_VeryVeryLongStupidUselessText_04 ) \
X(FAIL_VeryVeryLongStupidUselessText_05 ) \
X(FAIL_VeryVeryLongStupidUselessText_06 ) \
X(FAIL_VeryVeryLongStupidUselessText_07 ) \
X(FAIL_VeryVeryLongStupidUselessText_08 ) \
X(FAIL_VeryVeryLongStupidUselessText_09 ) \
X(FAIL_VeryVeryLongStupidUselessText_10 ) \
X(FAIL_VeryVeryLongStupidUselessText_11 ) \
X(FAIL_VeryVeryLongStupidUselessText_12 ) \
X(FAIL_VeryVeryLongStupidUselessText_13 ) \
X(FAIL_VeryVeryLongStupidUselessText_14 ) \
X(FAIL_VeryVeryLongStupidUselessText_15 ) \
X(FAIL_VeryVeryLongStupidUselessText_16 ) \
X(FAIL_VeryVeryLongStupidUselessText_17 ) \
X(FAIL_VeryVeryLongStupidUselessText_18 ) \
X(FAIL_VeryVeryLongStupidUselessText_19 ) \
X(FAIL_VeryVeryLongStupidUselessText_20 ) \
X(FAIL_VeryVeryLongStupidUselessText_21 ) \
X(FAIL_VeryVeryLongStupidUselessText_22 )

enum class EnumA : uint16_t
{
  #define X(name,value) name = value,
  ENUMS_A1
  #undef X
  Dummy_LastCommonResult,
  Dummy_FirstCommonFailure = 0x100,
  #define X(name) name,
  ENUMS_A2
  #undef X
  Dummy_LastCommonFailure,
  Dummy_FirstClassFailure = 0x1000,
};

constexpr static const char c_Text_Invalid[] = "<invalid>";

void PrintEnumAText (Print& i_Printer, EnumA i_EnumA);

#endif
