#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;   // private data
    double balance;

public:
    // constructor
    BankAccount(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;  // adding money
    }

    void showBalance() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // nested class inside BankAccount
    class Transaction {
    private:
        string type;
        double amount;

    public:
        Transaction(string t, double a) {
            type = t;
            amount = a;
        }

        void showTransaction() {
            cout << "Transaction Type: " << type << endl;
            cout << "Amount: " << amount << endl;
        }
    };
};

// inheritance
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, double bal, double rate)
        : BankAccount(accNo, bal) {
        interestRate = rate;
    }

    void addInterest() {
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    // nested class inside derived class
    class Loan {
    private:
        double loanAmount;

    public:
        Loan(double amt) {
            loanAmount = amt;
        }

        void showLoan() {
            cout << "Loan Amount: " << loanAmount << endl;
        }
    };
};

int main() {

    BankAccount acc(101, 5000);
    acc.deposit(1000);
    acc.showBalance();

    BankAccount::Transaction t1("Deposit", 1000);  // nested class use
    t1.showTransaction();

    cout << "--------------------------" << endl;

    SavingsAccount sacc(202, 10000, 5.5);
    sacc.showBalance();
    sacc.addInterest();

    SavingsAccount::Loan loan1(50000);  // nested in derived
    loan1.showLoan();

    return 0;
}