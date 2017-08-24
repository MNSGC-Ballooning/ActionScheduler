#include "Action.h"

Action::Action(unsigned long waitTime) {
	startTime = millis() + waitTime;
	this->waitTime = waitTime;
}

bool Action::check() {
	if (enabled && millis() > startTime) {
		execute();
		disable();
		return true;
	}
	else return false;
}

void Action::disable() {
	enabled = false;
}