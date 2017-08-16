#ifndef RepeatingAction_h
#define RepeatingAction_h

#include "Action.h"

class RepeatingAction : public Action {
	public:
		RepeatingAction(unsigned long waitTime):Action(waitTime){}
		virtual ~RepeatingAction(){}
		bool check();
	protected:
		virtual void execute() = 0;
};

#endif