#include "RepeatingAction.h"

bool RepeatingAction::check() {
	if (enabled && millis() - startTime > waitTime) {
		execute();
		startTime = millis();
	}
	return false;
}