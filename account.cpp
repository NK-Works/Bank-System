#include<iostream>
#include "account.h"
using namespace std;

namespace banking_system
{
    Account::Account() {}
    
    Account::Account(string name, double balance)
    {
        _name = name;
        _balance = balance;
    }

    Account::~Account() {}

    string Account::Name()
    {
        return _name;
    }

    void Account::Deposit(double amount)
    {
        _balance += amount;
    }

    void Account::Withdraw(double amount)
    {
        _balance -= amount;
    }

    double Account::Balance()
    {
        return _balance;
    }

    void Account::Print()
    {
        cout << "Name: " << Name() << endl;
        cout << "Balance: " << Balance() << endl;
    }

}

