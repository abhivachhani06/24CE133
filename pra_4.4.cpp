/*In a bid to design an efficient and user-friendly banking system, a structure was proposed that mirrors
the real-world operations of various account types. The foundation of the system is a base class
representing a generic bank account, encapsulating essential details such as account number and
balance. Building on this foundation, two specialized account types were created: a savings account,
which includes an interest rate as an additional feature, and a current account, which allows an
overdraft limit to accommodate specific customer needs.
To ensure proper initialization and cleanup of account objects, constructors and destructors were
implemented. Essential banking operations such as deposits and withdrawals were made available for
both account types, allowing users to perform and manage their transactions effectively. The system
also accounted for the need to track and manage transaction history, enabling operations such as
undoing the last transaction. This was achieved by simulating a mechanism to store a sequence of
transactions for each account type, providing insight into different ways of managing and organizing
data.*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Enum to represent transaction types
enum TransactionType { DEPOSIT, WITHDRAWAL };

// Struct to store transaction data
struct Transaction {
    TransactionType type;
    double amount;
};

// Base class for bank accounts
class BankAccount {
protected:
    int accountNumber;
    double balance;
    vector<Transaction> transactions; // History of transactions

public:
    // Constructor
    BankAccount(int accNo, double bal = 0.0) : accountNumber(accNo), balance(bal) {}

    // Destructor
    virtual ~BankAccount() {
        cout << "Account #" << accountNumber << " closed.\n";
    }

    // Deposit money and record transaction
    virtual void deposit(double amount) {
        balance += amount;
        transactions.push_back({ DEPOSIT, amount });
    }

    // Withdraw money and record transaction if allowed
    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back({ WITHDRAWAL, amount });
            return true;
        }
        cout << "Insufficient funds.\n";
        return false;
    }

    // Undo the last transaction
    void undoLastTransaction() {
        if (transactions.empty()) {
            cout << "No transaction to undo.\n";
            return;
        }

        Transaction last = transactions.back();
        if (last.type == DEPOSIT) {
            balance -= last.amount;
        } else if (last.type == WITHDRAWAL) {
            balance += last.amount;
        }

        transactions.pop_back(); // Remove last transaction
        cout << "Last transaction undone.\n";
    }

    // Display account details
    virtual void display() const {
        cout << "Account #" << accountNumber << " | Balance: $" << balance << endl;
    }
};

// Derived class for savings accounts
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Constructor with interest rate
    SavingsAccount(int accNo, double bal, double rate)
        : BankAccount(accNo, bal), interestRate(rate) {}

    void display() const override {
        BankAccount::display();
        cout << "Savings Account | Interest Rate: " << interestRate << "%\n";
    }
};

// Derived class for current accounts
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    // Constructor with overdraft limit
    CurrentAccount(int accNo, double bal, double limit)
        : BankAccount(accNo, bal), overdraftLimit(limit) {}

    // Override withdraw to include overdraft check
    bool withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            transactions.push_back({ WITHDRAWAL, amount });
            return true;
        }
        cout << "Overdraft limit exceeded.\n";
        return false;
    }

    void display() const override {
        BankAccount::display();
        cout << "Current Account | Overdraft Limit: $" << overdraftLimit << "\n";
    }
};

// Demonstration
int main() {
    cout << "=== Banking System ===\n";

    // Create accounts
    SavingsAccount savAcc(1001, 1000.0, 3.5);
    CurrentAccount curAcc(2001, 500.0, 300.0);

    // Display initial states
    savAcc.display();
    curAcc.display();

    // Perform transactions
    savAcc.deposit(200);
    savAcc.withdraw(150);
    savAcc.display();

    savAcc.undoLastTransaction(); // Undo last transaction
    savAcc.display();

    curAcc.withdraw(700); // Within overdraft
    curAcc.display();

    curAcc.withdraw(200); // Exceeds overdraft
    curAcc.undoLastTransaction(); // Undo last allowed transaction
    curAcc.display();

    return 0;
}

