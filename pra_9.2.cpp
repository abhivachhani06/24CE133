/*Imagine you are tasked with developing a simple banking system for a local financial institution. The
bank has observed an increase in customer complaints regarding unclear transaction records and
unhandled errors during operations. They want a robust software module to manage bank accounts
efficiently while maintaining a log of transactions.
As a software developer, your job is to create a banking system with the following features:
1. A way to represent individual bank accounts, including the ability to manage their balances.
2. Secure methods to deposit and withdraw funds.
3. An error-handling mechanism to address invalid operations, such as attempting to withdraw more
than the account's current balance.

4. A feature that logs every function call when an error occurs to provide insights into the issue.
The bank also insists on maintaining a history of transactions using basic data structures without
relying on advanced libraries or containers. Design and implement a banking system that fulfills the
above requirements.*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define a class for BankAccount
class BankAccount {
private:
    double balance;
    vector<string> transactionLog; // To keep track of transaction history

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("Failed deposit: Amount must be greater than 0.");
            cout << "Error: Amount must be greater than 0." << endl;
        } else {
            balance += amount;
            logTransaction("Deposited " + to_string(amount));
            cout << "Successfully deposited: " << amount << endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("Failed withdrawal: Amount must be greater than 0.");
            cout << "Error: Amount must be greater than 0." << endl;
        } else if (amount > balance) {
            logTransaction("Failed withdrawal: Insufficient funds.");
            cout << "Error: Insufficient funds." << endl;
        } else {
            balance -= amount;
            logTransaction("Withdrew " + to_string(amount));
            cout << "Successfully withdrew: " << amount << endl;
        }
    }

    // Method to get the current balance
    double getBalance() const {
        return balance;
    }

    // Method to print all transaction logs
    void printTransactionHistory() const {
        cout << "Transaction History:" << endl;
        for (const auto& transaction : transactionLog) {
            cout << transaction << endl;
        }
    }

private:
    // Method to log each transaction
    void logTransaction(const string& transaction) {
        transactionLog.push_back(transaction);
    }
};

int main() {
    // Create a bank account with an initial balance of 1000
    BankAccount account(1000);

    // Perform some transactions
    account.deposit(500);      // Valid deposit
    account.withdraw(200);     // Valid withdrawal
    account.withdraw(2000);    // Invalid withdrawal (insufficient funds)
    account.deposit(-50);      // Invalid deposit (negative amount)
    account.printTransactionHistory();  // Print transaction history

    // Display current balance
    cout << "Current balance: " << account.getBalance() << endl;

    return 0;
}

