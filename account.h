#ifndef ACCOUNT
#define ACCOUNT
#include<string>
using std::string;

namespace banking_system
{
    class Account
    {
    private:
        double _balance;
        string _name;
   
    public:
        Account();
        Account(string name, double balance);
        ~Account();
        
        string Name();
        double Balance();

        void Deposit(double amount);
        void Withdraw(double amount);
        void Print();
    };
}
#endif