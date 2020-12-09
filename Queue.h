#ifndef QUEUE_H
#define QUEUE_H

#include "Account.h"

// Queue_node for queue implementation
struct Queue_node
{
	// Constructor
	Queue_node(Account* ac1, Account* ac2, int am, Queue_node* p = NULL) : from(ac1), to(ac2), amount(am), link(p) {};

	// Data members with in-class initializers
	Account* from = NULL;
	Account* to = NULL;
	int amount = 0;
	Queue_node* link = NULL;
};


// Queue class for holding info about transactions
class Queue
{
public:
	~Queue();
	void enqueue(Account* ac1, Account* ac2, int am);
	Queue_node dequeue();
	bool is_empty();

	// Helper function
	void clear();
private:
	// Data members with in-class initializers
	int current_size = 0;
	Queue_node* first = NULL;
	Queue_node* last = NULL;

};

#endif // !QUEUE_H


