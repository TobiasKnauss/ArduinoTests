#ifndef STUCv1_h
#define STUCv1_h

#include <Arduino.h>
#include <MemoryTools.h>
#include <Result.h>

#include "STUC_failures.h"

struct STUCv1
{
  constexpr static char const *c_EnumNames_ClassFailures[]
  {
    #define X(name) #name,
    CLASS_FAILURES
    #undef X
  };

  enum class EResult : uint16_t
  {
    Dummy_FirstClassFailure = (uint16_t)::EResult::Dummy_FirstClassFailure,
    #define X(name) name,
    CLASS_FAILURES
    #undef X
  };

  static const char* GetResultText (EResult i_Result);

  ::EResult AnalyseMessage (byte* i_pRingBuffer,
                            uint16_t i_RingBufferLength);
};

#endif
