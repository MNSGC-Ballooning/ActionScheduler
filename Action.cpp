#include "Action.h"

Action::Action(unsigned long waitTime) {
	startTime = millis() + waitTime;
	this->waitTime = waitTime;
}

void Action::enable() {
	enabled = true;
}

void Action::disable() {
	enabled = false;
}