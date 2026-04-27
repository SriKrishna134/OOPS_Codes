#include <iostream>
#include <string>
using namespace std;

// Base class
class Account
{
private:
    int accNo;
    double balance;

public:
    Account(int a = 0, double b = 0)  // constructor
    {
        accNo = a;
        balance = b;
    }

    void deposit(double amt)
    {
        if (amt > 0)
            balance += amt;  // adding money
        else
            cout << "Invalid deposit amount" << endl;
    }

    void withdraw(double amt)
    {
        if (amt > balance)
            cout << "Insufficient Balance" << endl;
        else
            balance -= amt;  // deducting money
    }

    void display()
    {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }

    double getBalance()
    {
        return balance;  // getter
    }

    void setBalance(double b)
    {
        balance = b;  // setter
    }

    ~Account()
    {
        cout << "Account closed" << endl;
    }
};

// Derived class
class Savings : public Account
{
protected:
    double interestRate;

public:
    Savings(int a = 0, double b = 0, double r = 0) : Account(a, b)
    {
        interestRate = r;
    }

    void addInterest()
    {
        double interest = getBalance() * interestRate / 100;
        deposit(interest);  // adding interest
    }

    double getInterestRate()
    {
        return interestRate;
    }
};

// Another derived class
class PremiumSavings : public Savings
{
private:
    int rewardPoints;

public:
    PremiumSavings(int a = 0, double b = 0, double r = 0, int p = 0)
        : Savings(a, b, r)
    {
        rewardPoints = p;
    }

    void showDetails()
    {
        display();  // from base class
        cout << "Interest Rate: " << interestRate << endl;
        cout << "Reward Points: " << rewardPoints << endl;
    }
};

// forward declaration
class Bank;

class Auditor
{
public:
    void audit(Bank b);
};

// Bank class
class Bank
{
private:
    double totalFunds;

public:
    Bank()
    {
        totalFunds = 0;
    }

    void addFunds(double amt)
    {
        totalFunds += amt;
    }

    friend void Auditor::audit(Bank b);  // friend function
};

// friend function definition
void Auditor::audit(Bank b)
{
    cout << "Total Bank Funds: " << b.totalFunds << endl;
}

// static class example
class Logger
{
public:
    static int logCount;

    void log(string msg)
    {
        cout << "LOG: " << msg << endl;
        logCount++;  // counting logs
    }
};

int Logger::logCount = 0;

// main
int main()
{
    Savings s1(1001, 5000, 5);
    s1.deposit(1000);
    s1.addInterest();
    s1.display();

    cout << endl;

    PremiumSavings p1(2001, 10000, 7, 200);
    p1.showDetails();

    cout << endl;

    Logger l1;
    l1.log("Account Created");

    Logger l2;
    l2.log("Transaction Done");

    cout << "Total Logs: " << Logger::logCount << endl;

    cout << endl;

    Bank b1;
    b1.addFunds(50000);
    b1.addFunds(25000);

    Auditor a;
    a.audit(b1);

    cout << endl;

    s1.setBalance(10000);  // updating balance
    s1.display();

    cout << "Interest Rate (via getter): " << p1.getInterestRate() << endl;

    return 0;
}