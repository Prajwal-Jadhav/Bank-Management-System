#ifndef QUEUE_H
#define QUEUE_H

#include "Account.h"

// Node for queue implementation
struct Node
{
	// Constructor
	Node(Account* ac1, Account* ac2, int am, Node* p) : from(ac1), to(ac2), amount(am), link(p) {};

	// Data members with in-class initializers
	Account* from = NULL;
	Account* to = NULL;
	int amount = 0;
	Node* link = NULL;
};


class Queue
{
private:
	const int capacity = 3;

};

#endif // !QUEUE_H


