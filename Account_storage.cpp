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


// Populating accounts with data from text database account_database.txt
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


void Account_storage::initiate_transaction()
{
	std::cout << "\n\n********** Transaction initiated ************\n\n";

	// Get the address/reference to the account from which to send amount
	double amount_to_be_sent;
	std::cout << "Enter the amount to be sent: ";
	std::cin >> amount_to_be_sent;

	std::cout << std::endl;
	int from_account_id;
	std::cout << "\nEnter the id of account from which to send the amount: ";
	std::cin >> from_account_id;

	Account* from_account;
	try
	{
		from_account = list[from_account_id % size]->return_account_address(from_account_id);
	}
	catch (std::runtime_error& error)
	{
		std::cout << "No such account with given id " << from_account_id << " exists.\n";
		std::cout << "******* Terminating Transaction **********\n";
		return;
	}

	// Check if account has sufficient balance
	if (from_account->get_balance() < amount_to_be_sent)
	{
		std::cout << "Insufficient balance in the account\n";
		std::cout << "******* Terminating Transaction **********\n";
		return;
	}

	// Get the address/reference to the account from which to send amount
	std::cout << std::endl;
	int to_account_id;
	std::cout << "\nEnter the id of account to which send the amount: ";
	std::cin >> to_account_id;

	Account* to_account;
	try
	{
		to_account = list[to_account_id % size]->return_account_address(to_account_id);
	}
	catch (std::runtime_error& error)
	{
		std::cout << "No such account with given id " << to_account_id << " exists.\n";
		std::cout << "******* Terminating Transaction **********\n";
		return;
	}

	transactions.enqueue(from_account, to_account, amount_to_be_sent);
	std::cout << "\n******** Transaction Initiated Successfully **********\n\n";
}


// function to complete transactions in queue
void Account_storage::complete_a_transaction()
{
	if (transactions.is_empty())
	{
		std::cout << "\nCurrently there are no transactions pending\n";
		return;
	}

	Queue_node current_transaction = transactions.dequeue();

	Account* from_account = current_transaction.from;
	Account* to_account = current_transaction.to;
	double amount = current_transaction.amount;

	from_account->balance -= amount;
	to_account->balance += amount;

	std::cout << "**********  Transaction Completed Successfully  ************\n\n";

	std::cout << "Updated account information:\n";

	from_account->display();
	std::cout << "\n\n";

	to_account->display();
	std::cout << "\n";
}

