#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
	friend bool operator==(int target_id, Account acc);
public:
	Account();
	void display();
	
private:
	std::string name;
	int id;				// id for uniquely identifying account
	double balance;		// money in account
};


// Operator overloading useful for linked list implementation
bool operator==(int target_id, Account acc);

#endif // !ACCOUNT_H



