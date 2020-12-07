
#ifndef ACCOUNT_STORAGE_H
#define ACCOUNT_STORAGE_H

#include "Account.h"
#include "Linked_list.h"
#include <fstream>

class Account_storage
{
	Account_storage(int size = 15);
	~Account_storage();
	void populate_from_record(std::string file_name);
	void add_account(Account acc);
private:
	Linked_list** list;
	int size;
};

#endif 
