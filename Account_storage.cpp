#include "Account_storage.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor which reads input from  a 
// text file to create accounts
// Some code is remaining to be written
Account_storage::Account_storage(int sz)
{
	size = sz;
	list = new Linked_list*[sz];

	for (int i = 0; i < sz; ++i)
		list[i] = new Linked_list;

	populate_from_record();
}

// Destructor for deallocating storage
Account_storage::~Account_storage()
{
	for (int i = 0; i < size; ++i)
		list[i]->clear();

	delete[] list;
}


// Populating accounts with data from text databse account_database.txt
void Account_storage::populate_from_record()
{
	std::ifstream file("account_database.txt");

	if (!file.is_open())
	{
		std::cerr << "Failed to open account_database.txt file.\n";
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream is(line);
		int id; 
		std::string first_name;
		std::string last_name;
		double balance;

		is >> id >> first_name >> last_name >> balance;
		Account new_account(id, first_name + last_name, balance);

		list[id % size]->add_at_end(new_account);
	}

	std::cout << "Data loaded from database successfully!!\n";
	file.close();
}

void Account_storage::add_account()
{
	Account account;
	int id = account.get_id();
	list[id % size]->add_at_end(account);

	std::cout << "Account added successfully!!\nHere are details: \n";
	account.display();
}


