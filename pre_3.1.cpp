/*A growing organization sought to enhance its payroll process to improve accuracy and efficiency in
calculating employee salaries. The goal was to manage details such as the employee's name, basic
salary, and bonus amount. While most employees would receive a default bonus, there was a need
for flexibility to provide customized bonuses for exceptional performers or those in specialized roles.
To ensure real-time computation of each employee's total salary, the system would dynamically
calculate the total salary by adding the basic salary and the bonus. An inline function was chosen for
this task, allowing the system to compute the total salary instantly during processing. The system was
designed to initialize employee records using a constructor, where the bonus could either be set to a
default value or adjusted according to specific employee criteria.
As the organization expanded, managing employee records efficiently became a key consideration.
The solution involved storing employee details dynamically, ensuring the system could handle a
growing number of records while maintaining scalability and flexibility. Each employee record would
include their personal details, basic salary, and bonus information, with the system displaying a
breakdown of each employee’s details along with their total salary.*/
#include <iostream>
using namespace std;

class Employee {
private:
    string employeeName;
    float basicSalary;
    float bonus;

public:
    Employee(string name, float salary, float bonusAmount = 1000) {
        employeeName = name;
        basicSalary = salary;
        bonus = bonusAmount;
    }

    inline float calculateTotalSalary() {
        return basicSalary + bonus;
    }

    void displayEmployeeDetails() {
        cout << "Employee Name: " << employeeName << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
    }
};

int main() {
    Employee employee1("abhi", 50000);
    Employee employee2("archit", 60000, 2000);

    employee1.displayEmployeeDetails();
    cout << endl;
    employee2.displayEmployeeDetails();

    return 0;
}

