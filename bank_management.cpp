// bank_management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Bank Management Software

    Group members:
    1. Prajwal Jadhav - F19111004
    2. Pritish Kokare
    3. Ajay Kathwate

    A bank management software written in C++ using the concepts in data structures.
    Contains facilities to read account information in a text database.

    Accounts which contain name, balance, id, etc. are represented in memory using concepts
    such as array, linked list.

    This software has the ability to search for accounts using id. Furthermore, we can create an account
    as well as remove/delete an account

    There is ability to create a transaction to transfer balance from one account to the other. Transaction
    are stored in memory using a queue. As a result, we can complete a transaction using first in first out principle.

    We hope you find this project interesting. Thank you!
*/

#include <iostream>
#include "Account_storage.h"

int main()
{
    std::cout << "*************  Welcome to Bank Management System  **************\n";
    Account_storage accounts;

    while (true)
    {
        std::cout << "\nMain menu: Press the digit to perform action\n\n";
        std::cout << "0 - Exit\n";
        std::cout << "1 - Search for account\n";
        std::cout << "2 - Create new account\n";
        std::cout << "3 - Remove account by id\n";
        std::cout << "4 - Initiate a transaction\n";
        std::cout << "5 - Complete a pending transaction\n";

        int input;
        std::cin >> input;

        if (input == 0)
            break;
        else if (input == 1)
            accounts.search_account();
        else if (input == 2)
            accounts.add_account();
        else if (input == 3)
            accounts.remove_account();
        else if (input == 4)
            accounts.initiate_transaction();
        else if (input == 5)
            accounts.complete_a_transaction();
        else
            std::cout << "Please enter a valid input\n\n";
        
    }

    std::cout << "\n************** Thank you for using bank management system  *****************\n";
}

