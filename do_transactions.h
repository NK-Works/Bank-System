#ifndef DO_TRANSACTIONS
#define DO_TRANSACTIONS
#include<string>
#include"account.h"
using std::string;

namespace banking_system
{
    class DoTransactions
    {
    private:
    //     Account _account;
        double _ammount;

    public:
        // DoTransactions(Account& account);
        void DoWithdraw(Account& account);
        void DoDeposit(Account& account);
        void DoPrint(Account& account);
    };
}

#endif
