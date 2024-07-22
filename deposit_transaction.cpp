#include <iostream>
#include "account.h"
#include "deposit_transaction.h"
using namespace std;

namespace banking_system
{
    DepositTransaction::DepositTransaction(Account& account, double amount)  : _account(account), _amount(amount)
    {
        while (amount <= 0 || amount >= account.Balance())
        {
            cout << "Invalid Amount!\n";
        }
        _amount = amount;
    }

    bool DepositTransaction::Executed()
    {
        return _executed;
    }

    bool DepositTransaction::Success()
    {
        return _success;
    }

    bool DepositTransaction::Reversed()
    {
        return _reversed;
    }

    void DepositTransaction::Execute()
    {
        if (_executed && _success)
            throw invalid_argument("Already Executed\n");

        _executed = true;
        _account.Deposit(_amount);
        _success = true;
    }

    void DepositTransaction::Rollback()
    {
        if (!_executed && !_success)
            throw invalid_argument("No execution to rollback\n");

        if (_reversed)
            throw invalid_argument("Already rolled\n");

        _account.Withdraw(_amount);
        _reversed = true;
    }

    void DepositTransaction::Print()
    {
        cout << "For the account: " << _account.Name() << endl;

        if (!_executed)
            cout << "Execution failed\n";

        else if (!_success)
            cout << "Deposit failed\n";
        
        else if (_success && _reversed)
            cout << "Deposit reversed\n";
        
        else if (_success)
            cout << "Successful Deposit\n";

        _account.Print();
    }
}