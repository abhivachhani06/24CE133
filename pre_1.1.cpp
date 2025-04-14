/*A bank wants to create a simple system to manage customer bank accounts. The system should
allow customers to perform basic banking operations such as depositing money, withdrawing
money, and checking their account balance.
Each bank account will need to have an account holder's name, a unique account number, and
a balance. Deposits should increase the account balance, while withdrawals should only be
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more
money than is available, an error message should be displayed. Customers should also have the
ability to view their account balance whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on
creating a simple and efficient solution to manage the accounts effectively. The system should
ensure that all account details are secure and accessible only through authorized methods.*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber, double initialBalance = 0.0) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }


    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully.\n";
        }
    }

    // Display account details
    void displayAccountSummary() const {

        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }


    double getBalance() const {
        return balance;
    }
};


int main() {
    BankAccount account1("Abhi vachhani", 1001, 500.00);

    account1.displayAccountSummary();

    account1.deposit(250.00);
    account1.withdraw(100.00);
    account1.withdraw(1000.00); // Should show error

    cout << "\nFinal Balance: $" << account1.getBalance() << endl;

    return 0;
}
