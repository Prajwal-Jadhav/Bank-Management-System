#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Account.h"

struct Node
{
	Node(Account acc, Node* p = NULL) : data(acc), link(p) {};
	Node() : link(0) {};
	Account data;
	Node* link;
};

class Linked_list
{
public:
	bool isEmpty();
	void add_at_end(Account acc);
	void remove_by_id(int id);
	Account search(int id);
	int size();
	void clear();
	~Linked_list();
private:
	Node* first = NULL;
	Node* last = NULL;
};

#endif // !LINKED_LIST_H