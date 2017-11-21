#ifndef Scheduler_h
#define Schedule_h

#include "Action.h"

class Scheduler {
	public:
		void schedule(Action* action, String cancelTrigger = "");
		void cancel(String toCancel);
		void clear();
		void checkActions();
	private:
		class Node {
			public:
				Node(Action* action, String cancelTrigger);
				~Node();
				Action* action;
				Node* next = NULL;
				String cancelTrigger;
		};
		Node* head = NULL;
		void removeNode(Node* node);
};

#endif