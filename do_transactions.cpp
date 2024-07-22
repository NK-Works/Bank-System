#include<iostream>
#include"do_transactions.h"
#include"withdraw_transaction.h"
#include"deposit_transaction.h"
using namespace std;

namespace banking_system 
{
    // DoTransactions::DoTransactions(Account& account) : _account(account) {}

    void DoTransactions::DoWithdraw(Account& account)
    {
        cout << "Enter amount to withdraw: ";
        cin >> _ammount;

        try {
            WithdrawTransaction withdraw_trans(account, _ammount);
            withdraw_trans.Execute();
            withdraw_trans.Print();
        }
        catch (exception& e){
            cout << "Failed " << e.what() << endl;
        }
    }

    void DoTransactions::DoDeposit(Account& account)
    {
        cout << "Enter amount to deposit: ";
        cin >> _ammount;

        try {
            DepositTransaction deposit_trans(account, _ammount);
            deposit_trans.Execute();
            deposit_trans.Print();
        }
        catch (exception& e){
            cout << "Failed " << e.what() << endl;
        }
    }

    void DoTransactions::DoPrint(Account& account)
    {
        account.Print();
    }
}