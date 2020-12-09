#include "Account_storage.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor which reads input from  a 
// text file to create accounts
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
	std::cout << "\nStarting to load account database....\n\n";
	std::ifstream file("account_database.txt");

	if (!file.is_open())
	{
		std::cout << "Failed to open account_database.txt file.\n";
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
		Account new_account(id, first_name + " " + last_name, balance);

		list[id % size]->add_at_end(new_account);
	}

	std::cout << "Data loaded from database successfully!!\n\n";
	file.close();
}

void Account_storage::add_account()
{
	Account account;
	int id = account.get_id();
	list[id % size]->add_at_end(account);

	std::cout << "\n\n*********Account added successfully!!*************\n\nHere are details: \n";
	account.display();
}

void Account_storage::search_account()
{
	int search_id;
	std::cout << "\nEnter id for searching account: ";
	std::cin >> search_id;

	Account result_account = list[search_id % size]->search(search_id);

	if (result_account.get_id() == -1)
		std::cout << "\n*********Sorry, no account with id " << search_id << " exists.*************\n";
	else
		result_account.display();
}

void Account_storage::remove_account()
{
	int search_id;
	std::cout << "\nEnter id for removing account: ";
	std::cin >> search_id;

	int result = list[search_id % size]->remove_by_id(search_id);

	if (result == 0)
		std::cout << "\n\n*********  Account deleted successfully  ********\n\n";
	else
		std::cout << "\n\n********* No such account with given id exists ******** \n\n";
}


