#include "Account_storage.h"
#include <fstream>
#include <iostream>

// Constructor which reads input from  a 
// text file to create accounts
// Some code is remaining to be written
Account_storage::Account_storage(int sz = 10)
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
		std::cout << line << std::endl;
	}
}


