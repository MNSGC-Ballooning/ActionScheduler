#ifndef Action_h
#define Action_h

#include <Arduino.h>

class Action {
	public:
		Action(unsigned long waitTime);
		virtual ~Action(){}
		virtual bool check();
	protected:
		unsigned long startTime, waitTime;
		virtual void execute() = 0;
		bool enabled = true;
	private:
		void disable();
};

#endif