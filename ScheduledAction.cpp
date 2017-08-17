#include "ScheduledAction.h"

bool ScheduledAction::check() {
	if (enabled && millis() > startTime) {
		execute();
		return true;
	}
	else return false;
}