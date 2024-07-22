#ifndef DEPOSIT_TRANSACTION
#define DEPOSIT_TRANSACTION
#include"account.h"
#include<string>
using std::string;

namespace banking_system
{
    class DepositTransaction
    {
    private:
        Account& _account;
        double _amount;
        bool _executed = false;
        bool _success = false;
        bool _reversed = false;

    public:
        DepositTransaction(Account& account, double amount);

        bool Executed();
        bool Success();
        bool Reversed();

        void Execute();
        void Rollback();

        void Print();
    };
}
#endif