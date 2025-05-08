/*Imagine you're developing a financial calculator for a bank's system that allows users to calculate the

ratio of two monetary values they input. This tool must be reliable, as it's part of a crucial decision-
making process for loan eligibility.

A bank customer is required to enter two values directly into the system:
1. The first value represents the total loan amount they wish to apply for.
2. The second value represents their annual income.
The system will compute and display the ratio of the loan amount to the income, which helps the bank
assess the customer's loan-to-income ratio.
Major challenges that developer will face while developing the system would be, if the customer
mistakenly enters non-numerical characters (e.g., "abc"), the system should handle the situation
gracefully and prompt the user to correct their input. If the customer enters 0 as their annual income,
the system must identify this issue and avoid performing a division that would lead to an invalid result.*/
#include <iostream>
#include <limits>
using namespace std;

// Function to handle user input and ensure it's a valid number
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check if the input is valid (not a non-numeric value)
        if (cin.fail()) {
            // Clear the error state
            cin.clear();
            // Ignore incorrect input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
        } else {
            return value;
        }
    }
}

int main() {
    double loanAmount = getValidInput("Enter the loan amount: ");
    double annualIncome = getValidInput("Enter the annual income: ");

    // Check if annual income is zero to prevent division by zero
    if (annualIncome == 0) {
        cout << "Error: Annual income cannot be zero. Please enter a valid income." << endl;
        return 1; // Exit with an error code
    }

    // Calculate the loan-to-income ratio
    double ratio = loanAmount / annualIncome;

    // Display the result
    cout << "The loan-to-income ratio is: " << ratio << endl;
    return 0;
}

