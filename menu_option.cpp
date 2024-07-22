#include<iostream>
#include <limits>   // For std::numeric_limits *Important*
#include"menu_option.h"

using namespace std;
namespace banking_system
{
    // BankMenuOption::BankMenuOption() {};
    MenuOption BankMenuOption::ReadUserInput()
    {
        int sel_option;
        cout << "Available Operations:\n"
            << "1. Withdraw\n"
            << "2. Deposit\n"
            << "3. Print\n"
            << "4. Quit\n";

        cout << "Select Option: ";
        
        while (!(cin >> sel_option) || cin.peek() != '\n') {
            cout << "Invalid input.\n";
            cout << "Select Option: ";
            cin.clear();            // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard incorrect input
        }
        return static_cast<banking_system::MenuOption>(sel_option);
    };

}