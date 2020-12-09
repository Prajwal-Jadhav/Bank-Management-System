
#ifndef ACCOUNT_STORAGE_H
#define ACCOUNT_STORAGE_H

#include "Account.h"
#include "Linked_list.h"
#include "Queue.h"

class Account_storage
{
public:
	Account_storage(int sz = 10);
	~Account_storage();
	void add_account();
	void search_account();
	void remove_account();
	void initiate_transaction();
	void complete_a_transaction();
private:
	Linked_list** list;
	Queue transactions;
	int size;

	void populate_from_record();
};

#endif 
