/*A software development team is tasked with designing a system that can handle various geometric
shapes and compute their areas in a flexible way. The challenge is to create a system that can easily
extend to accommodate new types of shapes without altering the core functionality for each shape.
To accomplish this, the system is designed with a base class called Shape, which includes a virtual
function Area(). This function is meant to be overridden by each specific shape class to provide the
correct formula for calculating the area.
The derived classes, Rectangle and Circle, each implement the Area() function with their own
formulas: the Rectangle calculates the area using its length and width, while the Circle uses its radius.
This structure allows the system to treat all shapes uniformly through a common interface, enabling
easy extensibility. The goal is to use a single reference to the base class (Shape*) to calculate the area

of any shape, regardless of its type. This approach makes the system more adaptable, as new shapes
can be added later without disrupting existing code.
In managing a collection of shapes, there are two primary approaches: one method involves
dynamically managing a collection of shapes, allowing for easy addition and removal of shapes, while
the other relies on a static method that requires manually managing the size of the collection. Both
approaches aim to store and manage the shapes effectively, with one allowing automatic resizing as
needed while the other requires more manual handling.
Through this case study, the team will implement the base class Shape and the derived classes
Rectangle and Circle, each with their own Area() function. The students will gain a deeper
understanding of polymorphism, inheritance, and memory management while working with different
methods to store and manage the collection of shapes.*/
#include <iostream>
#include <vector>
using namespace std;

// Base class representing a generic shape
class Shape {
public:
    // Virtual function to calculate the area
    virtual double Area() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class representing a rectangle
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override Area function to compute rectangle area
    double Area() const override {
        return length * width;
    }
};

// Derived class representing a circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Override Area function to compute circle area
    double Area() const override {
        return 3.14159 * radius * radius;
    }
};

// Function to demonstrate polymorphism and manage shapes using a vector (dynamic)
void manageShapesWithVector() {
    vector<Shape*> shapes;

    // Dynamically create and store shapes in vector
    shapes.push_back(new Rectangle(4.0, 5.0));
    shapes.push_back(new Circle(3.0));

    // Compute and display area of all shapes
    for (Shape* shape : shapes) {
        cout << "Area: " << shape->Area() << endl;
    }

    // Cleanup dynamically allocated memory
    for (Shape* shape : shapes) {
        delete shape;
    }
}

// Function to demonstrate static array-based storage
void manageShapesWithArray() {
    Shape* shapes[2];
    shapes[0] = new Rectangle(4.0, 5.0);
    shapes[1] = new Circle(3.0);

    // Compute and display area of all shapes
    for (int i = 0; i < 2; ++i) {
        cout << "Area: " << shapes[i]->Area() << endl;
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }
}

int main() {
    cout << "Using vector (dynamic collection):\n";
    manageShapesWithVector();

    cout << "\nUsing static array (fixed size collection):\n";
    manageShapesWithArray();

    return 0;
}

