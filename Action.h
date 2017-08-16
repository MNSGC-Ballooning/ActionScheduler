#ifndef Action_h
#define Action_h

#include <Arduino.h>

class Action {
	public:
		Action(unsigned long waitTime);
		virtual ~Action(){}
		virtual bool check() = 0;
		void enable();
		void disable();
	protected:
		unsigned long startTime, waitTime;
		virtual void execute() = 0;
		bool enabled;
};

#endif