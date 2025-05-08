/*In an educational setting, an advanced grading system was conceptualized to accommodate the
diverse evaluation criteria for students at different academic levels. At the heart of the system is an
abstract base class that defines the grading framework. This class includes a protected member to
store marks and declares a pure virtual function for computing grades, ensuring that specific grading
logic is implemented by derived classes.
Two distinct derived classes were introduced to handle the unique grading needs of undergraduate
and postgraduate students. Each class defines its own implementation of the grade computation
method, reflecting the varying academic expectations for these groups. The system enables users to
input student data, compute grades based on the respective criteria, and manage a collection of
student records.*/
#include <iostream>
#include <vector>
#include <memory> // For smart pointers

using namespace std;

// Abstract base class
class Student {
protected:
    string name;
    int marks;

public:
    Student(string n, int m) : name(n), marks(m) {}

    // Pure virtual function: must be implemented by derived classes
    virtual string computeGrade() const = 0;

    // Virtual function to display student data and grade
    virtual void display() const {
        cout << "Name: " << name << ", Marks: " << marks
             << ", Grade: " << computeGrade() << endl;
    }

    // Virtual destructor
    virtual ~Student() {}
};

// Derived class for undergraduate students
class Undergraduate : public Student {
public:
    Undergraduate(string n, int m) : Student(n, m) {}

    string computeGrade() const override {
        if (marks >= 85) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 50) return "C";
        else return "F";
    }
};

// Derived class for postgraduate students
class Postgraduate : public Student {
public:
    Postgraduate(string n, int m) : Student(n, m) {}

    string computeGrade() const override {
        if (marks >= 90) return "A";
        else if (marks >= 75) return "B";
        else if (marks >= 60) return "C";
        else return "F";
    }
};

int main() {
    vector<shared_ptr<Student>> students; // Collection of student pointers

    // Sample input
    students.push_back(make_shared<Undergraduate>("Alice", 78));
    students.push_back(make_shared<Postgraduate>("Bob", 78));
    students.push_back(make_shared<Undergraduate>("Charlie", 92));
    students.push_back(make_shared<Postgraduate>("Diana", 88));

    cout << "=== Student Grades ===\n";
    for (const auto& student : students) {
        student->display(); // Polymorphic call to display and computeGrade
    }

    return 0;
}

