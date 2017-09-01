#include "Action.h"

Action::Action(unsigned long waitTime):
	waitTime(waitTime) {
	startTime = millis() + waitTime;
}

bool Action::check() {
	if (enabled && millis() > startTime) {
		execute();
		enabled = false;
		return true;
	}
	else return false;
}