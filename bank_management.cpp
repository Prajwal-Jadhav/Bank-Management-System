// bank_management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Account_storage.h"

int main()
{
    std::cout << "*************  Welcome to Bank Management System  **************\n\n";
    Account_storage accounts;

    while (true)
    {
        std::cout << "Main menu: Press the digit to perform action\n";
        std::cout << "0 - Exit\n";
        std::cout << "1 - Search for account\n";
        std::cout << "2 - Create new account\n";

        int input;
        std::cin >> input;

        if (input == 0)
            break;
    }

    std::cout << "\n************** Thank you for using bank management system  *****************\n";
}

