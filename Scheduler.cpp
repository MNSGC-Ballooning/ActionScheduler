#include "Scheduler.h"

void Scheduler::schedule(Action* action) {
	if (action == NULL) return;
	Node* temp = new Node(action);
	temp->next = head;
	head = temp;
}

void Scheduler::checkActions() {
	Node* runner = head;
	while (runner != NULL) {
		if (runner->action->check()) {
			Node* newNext = runner->next;
			if (runner == head) {
				delete head;
				head = newNext;
				runner = head;
			}
			else {
				Node* prev = head;
				while (prev->next != runner) {
					prev = prev->next;
				}
				prev->next = newNext;
				delete runner;
				runner = newNext;
			}
		}
		else
			runner = runner->next;
	}
}

Scheduler::Node::Node(Action* action) {
	this->action = action;
}

Scheduler::Node::~Node() {
	delete action;
}