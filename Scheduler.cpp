#include "Scheduler.h"

void Scheduler::schedule(Action* action) {
	if (action == NULL) return;
	for (Node* runner = head; runner != NULL; runner = runner->next) {
		if (action == runner->action) return;
	}
	Node* newHead = new Node(action, "");
	newHead->next = head;
	head = newHead;
}

void Scheduler::schedule(Action* action; String cancelTrigger) {
	if (action == NULL) return;
	for (Node* runner = head; runner != NULL; runner = runner->next) {
		if (action == runner->action) return;
	}
	Node* newHead = new Node(action, cancelTrigger);
	newHead->next = head;
	head = newHead;
}

void Scheduler::cancel(String toCancel) {
	for (Node* runner = head; runner != NULL;) {
		if (toCancel.equals(runner->cancelTrigger)) {
			Node* checked = runner;
			runner = runner->next;
			removeNode(checked);
		}
		else
			runner = runner->next;
	}
}

void Scheduler::clear() {
	while (head != NULL) {
		removeNode(head);
	}
}

void Scheduler::checkActions() {
	for (Node* runner = head; runner != NULL;) {
		if (runner->action->check()) {
			Node* checked = runner;
			runner = runner->next;
			removeNode(checked);
		}
		else
			runner = runner->next;
	}
}

Scheduler::Node::Node(Action* action, String cancelTrigger) {
	this->action = action;
	this->cancelTrigger = cancelTrigger;
}

Scheduler::Node::~Node() {
	delete action;
}

void Scheduler::removeNode(Node* node) {
	if (node == head) {
		node = head->next;
		delete head;
		head = node;
	}
	else {
		Node* prev = head;
		while (prev->next != node) {
			prev = prev->next;
		}
		prev->next = node->next;
		delete node;
	}
}