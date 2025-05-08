/*A software development team is working on an advanced simulation system that involves hierarchical
object management. The system includes a base class that defines general behavior and derived
classes that introduce specialized functionality, including dynamic resource allocation. During testing,
the team encounters unexpected memory leaks when deleting objects through base class pointers,
raising concerns about proper resource management.
To investigate the issue, the team examines how object destruction works in an inheritance hierarchy.
They create a base class that serves as a foundation for derived classes, but they notice that when a
Base* pointer is used to delete a Derived object, the destructor of the derived class is not invoked.
This results in dynamically allocated resources remaining in memory, causing resource leakage.
To resolve this problem, the team explores the concept of virtual destructors. By marking the base
class destructor as virtual, they ensure that the destructor of the derived class is correctly called when
deleting an object through a base class pointer. This guarantees proper deallocation of dynamically
allocated resources, preventing memory leaks.
Since the project requires manual memory management, the team uses raw pointers and the new and
delete operators to allocate and release resources.*/
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    Base() {
        cout << "Base Constructor\n";
    }

    // Virtual destructor to ensure proper destruction in derived classes
    virtual ~Base() {
        cout << "Base Destructor\n";
    }

    virtual void display() const {
        cout << "Base class\n";
    }
};

// Derived class
class Derived : public Base {
private:
    int* data; // Simulating dynamic memory allocation

public:
    Derived() : data(new int[100]) { // Allocate memory dynamically
        cout << "Derived Constructor\n";
    }

    // Virtual destructor to clean up resources in derived class
    ~Derived() {
        delete[] data; // Deallocate dynamically allocated memory
        cout << "Derived Destructor\n";
    }

    void display() const override {
        cout << "Derived class\n";
    }
};

int main() {
    Base* obj = new Derived(); // Base pointer to Derived object
    obj->display(); // Calls Derived class method
    delete obj; // Properly calls Derived destructor due to virtual destructor

    return 0;
}

