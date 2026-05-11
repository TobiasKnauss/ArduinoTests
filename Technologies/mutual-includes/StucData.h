#ifndef StucData_h
#define StucData_h

#include <Arduino.h>
#include "STUC.h"

struct StucData
{
  STUC::EAction Action = STUC::EAction::None;

  StucData (STUC::EAction i_Action);

  void Clear ();
};

#endif
