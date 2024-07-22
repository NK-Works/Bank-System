#include <iostream>
#include "account.h"
#include "withdraw_transaction.h"
using namespace std;

namespace banking_system
{
    WithdrawTransaction::WithdrawTransaction(Account& account, double amount)  : _account(account), _amount(amount)
    {
        while (amount <= 0 || amount >= account.Balance())
        {
            cout << "Invalid Amount!\n";
        }
        _amount = amount;
    }

    bool WithdrawTransaction::Executed()
    {
        return _executed;
    }

    bool WithdrawTransaction::Success()
    {
        return _success;
    }

    bool WithdrawTransaction::Reversed()
    {
        return _reversed;
    }

    void WithdrawTransaction::Execute()
    {
        if (_executed && _success)
            throw invalid_argument("Already Executed\n");

        _executed = true;
        _account.Withdraw(_amount);
        _success = true;
    }

    void WithdrawTransaction::Rollback()
    {
        if (!_executed && !_success)
            throw invalid_argument("No execution to rollback\n");

        if (_reversed)
            throw invalid_argument("Already rolled\n");

        _account.Deposit(_amount);
        _reversed = true;
    }

    void WithdrawTransaction::Print()
    {
        cout << "For the account: " << _account.Name() << endl;

        if (!_executed)
            cout << "Execution failed\n";

        else if (!_success)
            cout << "Withdrawal failed\n";
        
        else if (_success && _reversed)
            cout << "Withdrawal reversed\n";
        
        else if (_success)
            cout << "Successful withdrawal\n";

        _account.Print();
    }
}