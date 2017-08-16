#ifndef Scheduler_h
#define Schedule_h

#include "Action.h"

class Scheduler {
	public:
		Scheduler();
		void schedule(Action* action);
		void checkActions();
	private:
		class Node {
			public:
				Node(Action* action);
				~Node();
				Action* action;
				Node* next;
		};
		Node* head;
};

#endif