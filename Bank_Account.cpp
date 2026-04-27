//This example demonstrates encapsulation, data protection, and object interaction ?

#include <iostream>
using namespace std;

class BankAccount
{
private:
    int balance;
    string accountHolder;
    int accountNumber;
    static int totalAccounts;   // shared by all accounts

public:
    // constructor → runs when object is created
    BankAccount(string name, int initialBalance)
    {
        accountHolder = name;
        balance = initialBalance;
        totalAccounts++;  // counting accounts
        accountNumber = totalAccounts;

        cout << "Account created for " << name 
             << " (A/C No: " << accountNumber << ")" << endl;
    }

    void deposit(int amount)
    {
        if(amount > 0)
        {
            balance += amount;  // adding money
            cout << "Deposited: Rs " << amount << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw(int amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid amount!" << endl;
        }
        else if(amount <= balance)
        {
            balance -= amount;  // deducting money
            cout << "Withdrawn: Rs " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void showBalance()
    {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs " << balance << endl;
        cout << "------------------------" << endl;
    }

    // static function → belongs to class, not object
    static void showTotalAccounts()
    {
        cout << "Total bank accounts: " << totalAccounts << endl;
    }
};

// initializing static variable
int BankAccount::totalAccounts = 0;

int main()
{
    BankAccount acc1("Rahul Sharma", 5000);
    BankAccount acc2("Priya Patel", 10000);

    acc1.deposit(2000000);
    acc1.withdraw(1000);
    acc1.showBalance();

    acc2.withdraw(15000000);  // more than balance
    acc2.showBalance();

    BankAccount::showTotalAccounts();  // calling static function

    return 0;
}