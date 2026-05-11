#include "STUC.h"
#include "StucData.h"

STUC::STUC (uint32_t i_DeviceId)
{
  m_DeviceId = i_DeviceId;
}

bool STUC::Compose (StucData& i_Data)
{
  i_Data.Clear ();
  return i_Data.Action == EAction::Read;
}
