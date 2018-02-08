#include "RepeatingAction.h"

bool RepeatingAction::check() {
  if (enabled && millis() > startTime) {
    execute();
    startTime = millis() + waitTime;
  }
  return false;
}