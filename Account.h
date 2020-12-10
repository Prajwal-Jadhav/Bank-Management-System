#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account_storage;

class Account
{
	friend bool operator==(int target_id, Account acc);
	friend class Account_storage;
public:
	Account();
	Account(int i, std::string n, double b);
	void display();
	int get_id();
	double get_balance();
	
private:
	std::string name;
	int id;				// id for uniquely identifying account
	double balance;		// money in account
};


// Operator overloading useful for linked list implementation
bool operator==(int target_id, Account acc);

#endif // !ACCOUNT_H



