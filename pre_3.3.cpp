/*A community bank sought to enhance its account management system with a digital solution to
improve efficiency and provide better customer service. The system was required to manage the
essential details of each account, including the account number, account holder’s name, and balance.
Additionally, the bank wanted to provide a secure mechanism for transferring money between
accounts, allowing customers to easily manage their funds.
The bank also needed a way to track the total number of accounts created, which would be important
for generating reports and understanding the growth of their customer base. This feature was aimed
at helping the bank maintain an overview of their account portfolio and analyze trends over time.
To ensure smooth and reliable operations, the system was designed to store account information in a
way that would allow easy access and updates. When new accounts were created, they would be
added to the system dynamically. The management team planned for future scalability and
performance improvements by considering more efficient storage and retrieval methods after the
initial system was built, ensuring that the bank could easily accommodate more accounts and
transactions as the customer base grew.*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    static int totalAccounts;

    BankAccount(int accNum, string holderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = initialBalance;
        totalAccounts++;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    void transfer(BankAccount &other, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            other.balance += amount;
            cout << "Transferred " << amount << " to account " << other.accountNumber << endl;
        } else {
            cout << "Insufficient balance for transfer." << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int BankAccount::totalAccounts = 0;

int main() {
    BankAccount acc1(1001, "abhi", 5000.0);
    BankAccount acc2(1002, "archit", 3000.0);

    acc1.displayAccountDetails();
    acc2.displayAccountDetails();

    acc1.deposit(1500.0);
    acc1.withdraw(2000.0);
    acc1.transfer(acc2, 1000.0);

    cout << "Total accounts created: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}

