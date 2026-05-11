#ifndef STUC_h
#define STUC_h

#include <Arduino.h>

class StucData;

class STUC
{
  uint32_t m_DeviceId;
  
public:
  enum class EAction : uint8_t
  {
    None  = 0,
    Read  = 1,
    Write = 2
  };

  STUC (uint32_t i_DeviceId);

  bool Compose (StucData& i_Data);
};

#endif
