#include "StucData.h"

StucData::StucData (STUC::EAction i_Action)
{
  Action = i_Action;
}

void StucData::Clear ()
{
  Action = STUC::EAction::None;
}