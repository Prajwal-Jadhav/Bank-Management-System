
#ifndef ACCOUNT_STORAGE_H
#define ACCOUNT_STORAGE_H

#include "Account.h"
#include "Linked_list.h"

class Account_storage
{
public:
	Account_storage(int sz = 10);
	~Account_storage();
	void add_account();
	void search_account();
	void remove_account();
private:
	Linked_list** list;
	int size;

	void populate_from_record();
};

#endif 
