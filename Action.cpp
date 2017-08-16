#include "Action.h"

Action::Action(unsigned long waitTime) {
	startTime = millis();
	this->waitTime = waitTime;
}

void Action::enable() {
	enabled = true;
}

void Action::disable() {
	enabled = false;
}