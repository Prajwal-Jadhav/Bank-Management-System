
#ifndef ACCOUNT_STORAGE_H
#define ACCOUNT_STORAGE_H

#include "Account.h"
#include "Linked_list.h"

class Account_storage
{
public:
	Account_storage(int size = 15);
	~Account_storage();
	void populate_from_record();
	void add_account(Account acc);
private:
	Linked_list** list;
	int size;
};

#endif 
