/*A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.

To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.

EMI=
P ∗ R ∗ (1 + R)^T
((1+R)^T) −1

As part of the implementation, the developers planned to initialize loans either with default values for
testing purposes or with actual customer data provided at the time of application. The system needed

to include a feature to display comprehensive loan details, including the calculated EMI, in a customer-
friendly format. This functionality was intended to aid both customers and bank staff in managing

loan-related queries effectively.*/
#include <iostream>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    float loanAmount;
    float annualInterestRate;
    int loanTenureMonths;

public:
    Loan() {
        loanID = 0;
        applicantName = "Default Name";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        loanTenureMonths = 0;
    }

    Loan(int id, string name, float amount, float interestRate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = interestRate;
        loanTenureMonths = tenure;
    }

    float calculateEMI() {
        float monthlyInterestRate = (annualInterestRate / 100) / 12;
        float emi = loanAmount * monthlyInterestRate / (1 - 1 / (1 + monthlyInterestRate) * loanTenureMonths);
        return emi;
    }

    void displayLoanDetails() {
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure (Months): " << loanTenureMonths << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};

int main() {
    Loan loan1(133, "abhi", 500000, 6.5, 120);
    Loan loan2(136, "archit", 300000, 7.0, 60);

    loan1.displayLoanDetails();
    cout << endl;
    loan2.displayLoanDetails();

    return 0;
}

