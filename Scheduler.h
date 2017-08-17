#ifndef Scheduler_h
#define Schedule_h

#include "Action.h"

class Scheduler {
	public:
		Scheduler();
		void schedule(Action* action);
		void Schedule(Action* action, String cancelTrigger);
		void cancel(String toCancel);
		void clear();
		void checkActions();
	private:
		class Node {
			public:
				Node(Action* action, String cancelTrigger);
				~Node();
				Action* action;
				Node* next;
				String cancelTrigger;
		};
		Node* head;
		void removeNode(Node* node);
};

#endif