#ifndef WITHDRAW_TRANSACTION
#define WITHDRAW_TRANSACTION
#include"account.h"
#include<string>
using std::string;

namespace banking_system
{
    class WithdrawTransaction
    {
    private:
        Account& _account;
        double _amount;
        bool _executed = false;
        bool _success = false;
        bool _reversed = false;

    public:
        WithdrawTransaction(Account& account, double amount);

        bool Executed();
        bool Success();
        bool Reversed();

        void Execute();
        void Rollback();

        void Print();
    };
}
#endif