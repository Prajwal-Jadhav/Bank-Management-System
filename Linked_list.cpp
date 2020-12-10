#include "Linked_list.h"
#include <iostream>

bool Linked_list::isEmpty()
{
	return first == NULL;
}

int Linked_list::size()
{
	Node* current = first;
	int count = 0;
	while (current != NULL)
	{
		++count;
		current = current->link;
	}
	return count;
}

void Linked_list::add_at_end(Account acc)
{
	if (first == NULL)
	{
		first = last = new Node(acc, NULL);
	}
	else
	{
		Node* new_node = new Node(acc, NULL);
		last->link = new_node;
		last = last->link;
	}
}

int Linked_list::remove_by_id(int id)
{
	if (first == NULL)	// if list is empty
	{
		return 1; // indicating failure
	}
	else if (id == first->data)  // first is the required one
	{
		auto temp = first;
		first = first->link;
		delete temp;

		if (first == NULL)	// if there was only one element in list
			last = NULL;

		return 0; // indicating success
	}
	else
	{
		auto trailcurrent = first;
		auto current = first->link;

		bool found = false;

		while (current != NULL && !found)
		{
			if (id == current->data)
			{
				found = true;
				break;
			}

			trailcurrent = current;
			current = current->link;
		}

		if (found)
		{
			trailcurrent->link = current->link;

			if (current == last)	// if required element was the first one
				last = trailcurrent;

			delete current;
			return 0;  // indicating success
		}
		else
		{
			return 1;  // indicating failure
		}
	}
	
}

// finds account with given id if account doesn't exist then return fake/error account
Account Linked_list::search(int search_id)
{
	Node* current = first;

	while (current != NULL)
	{
		if (search_id == current->data)
			return current->data;

		current = current->link;
	}

	// if doesn't exits return error/ fake account
	return Account(-1, "", 0.0);
}

// Helper function for clearing/deallocating memory
// And returning list to initial condition
void Linked_list::clear()
{
	Node* current = first;
	while (current != NULL)
	{
		auto temp = current;
		current = current->link;
		delete temp;
	}

	first = NULL;
}

// Destructor
Linked_list::~Linked_list()
{
	this->clear();
}

// Returns pointer to the account with given id
Account* Linked_list::return_account_address(int search_id)
{
	if (first == NULL)
		throw std::runtime_error("No element with such id exists\n");
	else if (search_id == first->data)
		return &(first->data);
	else
	{
		auto current = first;
		while (current != NULL)
		{
			if (search_id == current->data)
				return &(current->data);
			else
				current = current->link;
		}
	}

	// if no account is found
	throw std::runtime_error("No element with such id exists\n");
}
