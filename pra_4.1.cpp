/*A team of engineers was tasked with developing a program to calculate and manage the areas of

multiple circles for a design project. To achieve this, they devised a solution using a structured, object-
oriented approach. At the foundation of their solution was a base class that represented a generic

shape, responsible for storing and managing the radius of the circle. Building upon this, a specialized
class for circles was created to extend functionality by introducing a method for calculating the area
of a circle based on its radius. Using this framework, the team designed a system to handle multiple
circles, ensuring that the process of storing, calculating, and displaying the areas was efficient and
adaptable. They explored two different approaches for managing the collection of circles—one
focusing on flexibility and dynamic handling, while the other used a more static structure. By
implementing and comparing these methods, the engineers gained insights into the benefits of using
efficient techniques for organizing and processing geometric data, enhancing their problem-solving
capabilities.*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

// Base class for Shape
class Shape {
protected:
    double radius;
public:
    Shape(double r = 0.0) : radius(r) {}

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }
};

// Derived class for Circle
class Circle : public Shape {
public:
    Circle(double r = 0.0) : Shape(r) {}

    double calculateArea() const {
        return PI * radius * radius;
    }
};

// Function to handle circles using dynamic collection (vector)
void handleCirclesDynamically() {
    int n;
    cout << "Enter number of circles (dynamic approach): ";
    cin >> n;

    vector<Circle> circles;

    for (int i = 0; i < n; ++i) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles.emplace_back(r);
    }

    cout << "\nAreas of Circles (Dynamic Collection):\n";
    for (int i = 0; i < circles.size(); ++i) {
        cout << "Circle " << i + 1 << " Area: " << circles[i].calculateArea() << endl;
    }
}

// Function to handle circles using static collection (array)
void handleCirclesStatically() {
    const int MAX_CIRCLES = 5;
    Circle circles[MAX_CIRCLES];

    cout << "\nUsing Static Array (Fixed Size: " << MAX_CIRCLES << ")\n";
    for (int i = 0; i < MAX_CIRCLES; ++i) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles[i].setRadius(r);
    }

    cout << "\nAreas of Circles (Static Collection):\n";
    for (int i = 0; i < MAX_CIRCLES; ++i) {
        cout << "Circle " << i + 1 << " Area: " << circles[i].calculateArea() << endl;
    }
}

// Main function
int main() {
    cout << "=== Circle Area Manager ===\n\n";

    handleCirclesDynamically();
    cout << "\n-----------------------------\n";
    handleCirclesStatically();

    return 0;
}

