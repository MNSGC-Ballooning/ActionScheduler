#ifndef ScheduledAction_h
#define ScheduledAction_h

#include "Action.h"

class ScheduledAction : public Action {
	public:
		ScheduledAction(unsigned long waitTime):Action(waitTime){}
		virtual ~ScheduledAction(){}
		bool check();
	protected:
		virtual void execute() = 0;
};

#endif