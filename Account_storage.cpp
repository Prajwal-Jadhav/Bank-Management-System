#include "Account_storage.h"

// Constructor which reads input from  a 
// text file to create accounts
// Some code is remaining to be written
Account_storage::Account_storage(int sz = 15)
{
	size = sz;
	list = new Linked_list*[sz];

	for (int i = 0; i < sz; ++i)
		list[i] = new Linked_list;
}

// Destructor for deallocating storage
Account_storage::~Account_storage()
{
	for (int i = 0; i < size; ++i)
		list[i]->clear();

	delete[] list;
}


