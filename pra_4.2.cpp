/*A growing organization wanted to develop a system to manage its hierarchy and represent its
structure in a programmatic way. To achieve this, a multilevel approach was designed, reflecting the
natural progression of roles within the organization. At the foundation, a class was created to
represent a person, capturing the basic details such as name and age. Building on this, an intermediate
level was introduced to represent employees, adding a unique identifier for each. Finally, at the
topmost level, a class for managers was created, which included additional details such as the
department they oversee.
The system needed to handle the initialization of all these attributes through constructors at each
level, ensuring the proper propagation of information across the hierarchy. Additionally, the
functionality to display details at every level was included to provide clear insights into the
organization's structure. Two approaches were explored for managing multiple managers: one relied
on an efficient method for retrieval and organization based on employee identifiers, while the other
used a straightforward and static method for storage.*/
#include <iostream>
#include <map>
#include <string>

using namespace std;


// Base Class: Person

class Person {
protected:
    string name;
    int age;

public:
    // Constructor for Person
    Person(string n = "", int a = 0) : name(n), age(a) {}

    // Display basic person details
    virtual void display() const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};


// Derived Class: Employee

class Employee : public Person {
protected:
    int employeeID;

public:
    // Constructor chaining to Person
    Employee(string n = "", int a = 0, int id = 0) : Person(n, a), employeeID(id) {}

    // Display employee details
    void display() const override {
        Person::display(); // Call base class display
        cout << "Employee ID: " << employeeID << endl;
    }

    // Getter for employee ID (for map key lookup)
    int getID() const {
        return employeeID;
    }
};


// Derived Class: Manager

class Manager : public Employee {
private:
    string department;

public:
    // Constructor chaining to Employee (and thus Person)
    Manager(string n = "", int a = 0, int id = 0, string dept = "")
        : Employee(n, a, id), department(dept) {}

    // Display manager details
    void display() const override {
        Employee::display(); // Call parent class display
        cout << "Department: " << department << endl;
    }
};


// Dynamic/Efficient Storage: Using std::map

void handleManagersEfficiently() {
    int n;
    cout << "\nEnter number of managers (efficient storage): ";
    cin >> n;

    map<int, Manager> managerMap;  // Key: employee ID

    // Input manager details and insert into map
    for (int i = 0; i < n; ++i) {
        string name, department;
        int age, id;

        cout << "\nManager " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin.ignore();
        getline(cin, department);

        // Insert into map using employee ID as key
        managerMap[id] = Manager(name, age, id, department);
    }

    // Display all managers from map
    cout << "\nDisplaying Managers (Efficient Storage):\n";
    for (const auto& pair : managerMap) {
        cout << "\nEmployee ID: " << pair.first << endl;
        pair.second.display();
    }

    // Optional retrieval by ID
    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;
    if (managerMap.find(searchID) != managerMap.end()) {
        cout << "Manager Found:\n";
        managerMap[searchID].display();
    } else {
        cout << "Manager with ID " << searchID << " not found.\n";
    }
}


// Static Storage: Using Fixed-Size Array

void handleManagersStatically() {
    const int MAX_MANAGERS = 3; // Can be adjusted as needed
    Manager managers[MAX_MANAGERS]; // Fixed array of managers

    cout << "\nUsing Static Array (Max " << MAX_MANAGERS << " managers)\n";

    // Input data into array
    for (int i = 0; i < MAX_MANAGERS; ++i) {
        string name, department;
        int age, id;

        cout << "\nManager " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin.ignore();
        getline(cin, department);

        // Assign to array
        managers[i] = Manager(name, age, id, department);
    }

    // Display all managers
    cout << "\nDisplaying Managers (Static Storage):\n";
    for (int i = 0; i < MAX_MANAGERS; ++i) {
        cout << "\nManager " << i + 1 << ":\n";
        managers[i].display();
    }
}


// Main Function

int main() {
    cout << "=== Organization Hierarchy Manager ===\n";

    // Efficient manager handling using map
    handleManagersEfficiently();

    cout << "\n-----------------------------\n";

    // Static manager handling using array
    handleManagersStatically();

    return 0;
}
