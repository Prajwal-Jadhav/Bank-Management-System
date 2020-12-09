#include "Queue.h"

void Queue::clear()
{
	while (first != NULL)
	{
		auto temp = first;
		first = first->link;
		delete temp;
	}

	first = NULL;
	last = NULL;
	current_size = 0;
}

Queue::~Queue()
{
	clear();
}

void Queue::enqueue(Account* ac1, Account* ac2, int am)
{
	Queue_node* new_node = new Queue_node(ac1, ac2, am);

	if (first == NULL)  // if queue is empty
	{
		first = new_node;
		last = first;
	}
	else
	{
		last->link = new_node;
		last = last->link;
	}

	++current_size;
}

Queue_node Queue::dequeue()
{
	Queue_node result = *first;

	auto temp = first;
	first = first->link;
	delete temp;

	if (first == NULL)   // if there was only one element in queue
		last = NULL;

	--current_size;

	return result;
}

bool Queue::is_empty()
{
	return (first == NULL);
}

