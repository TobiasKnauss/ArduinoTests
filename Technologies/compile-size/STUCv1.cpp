#include "STUCv1.h"

//--------------------------------------------------------------------
constexpr char const *STUCv1::c_EnumNames_ClassFailures[];

//--------------------------------------------------------------------
const char* STUCv1::GetResultText (STUCv1::EResult i_Result)
{
  if (i_Result < EResult::Dummy_FirstClassFailure)
    return ::GetResultText ((::EResult)i_Result);
  return c_EnumNames_ClassFailures[((int)i_Result)];
}

//--------------------------------------------------------------------
EResult STUCv1::AnalyseMessage (byte* i_pRingBuffer,
                                uint16_t i_RingBufferLength)
{
  for (uint16_t searchIndex = 0; searchIndex < i_RingBufferLength; searchIndex++)
  {
    uint8_t* pSearch = i_pRingBuffer + searchIndex;
    if (pSearch >= i_pRingBuffer + i_RingBufferLength)
      pSearch -= i_RingBufferLength;
    
    if (*pSearch != 0)
      continue;

    uint8_t flags = 0;
    if (Serial.read())
      return ::EResult::FAIL_Buffer_GetValue;
  }

  return (::EResult)EResult::FAIL_Message_NotFound;
}

