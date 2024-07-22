#ifndef MENU_OPTION
#define MENU_OPTION

namespace banking_system
{
    enum MenuOption
    {
        Withdraw = 1,
        Deposit,
        Print,
        Quit
    };

    class BankMenuOption 
    {
    public:
        // BankMenuOption();
        MenuOption ReadUserInput();
    };
}
#endif