#include "ScheduledAction.h"

bool ScheduledAction::check() {
	if (enabled && millis() - startTime > waitTime) {
		execute();
		return true;
	}
	else return false;
}