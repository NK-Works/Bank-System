#include <iostream>
#include "account.h"
#include "menu_option.h"
#include"do_transactions.h"

using namespace std;
using namespace banking_system;

int main()
{
    Account a1("Anneshu Nag", 5000);
    // a1.Print();
    // a1.Deposit(100);
    // a1.Print();

    // a1.Withdraw(50);
    // a1.Print();
    MenuOption option_sel;
    BankMenuOption bank_options;
    DoTransactions do_transactions;
    do
    {
        option_sel = bank_options.ReadUserInput();

        switch (option_sel)
        {
        case MenuOption::Withdraw:
            do_transactions.DoWithdraw(a1);
            break;
        case MenuOption::Deposit:
            do_transactions.DoDeposit(a1);
            break;
        case MenuOption::Print:
            do_transactions.DoPrint(a1);
            break;
        case MenuOption::Quit:
            cout << "Exiting program.\n";
            return 1;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (option_sel != Quit);

    return 0;
}