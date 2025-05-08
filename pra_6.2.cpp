/*In a digital mapping application, a team of developers is working on a feature that allows objects to
be repositioned dynamically on a coordinate plane. The application requires precise control over the
movement of individual points representing user-defined markers. To achieve this, the team needs to
design a system that allows a point’s coordinates to be adjusted efficiently while maintaining a fluid
and chainable update mechanism.
To ensure seamless movement, the developers must implement a structure that allows each point to
shift by specified offsets in the x and y directions. Additionally, the solution should be designed in a
way that supports method chaining, enabling multiple transformations to be applied in a single
statement. This requires careful handling of object references, utilizing this pointer to return the
updated object.
Furthermore, the implementation must be optimized for direct memory management, ensuring that
objects are updated through pass-by-reference using pointers.*/
#include <iostream>
using namespace std;

class Point {
private:
    double x, y;

public:
    // Constructor to initialize the point
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Method to move the point by offsets (x_offset, y_offset)
    Point& move(double x_offset, double y_offset) {
        x += x_offset;
        y += y_offset;
        return *this; // Return the updated object for method chaining
    }

    // Display the point coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(2, 3);
    p.move(1, 1).move(-1, -1).move(2, 3); // Chainable movements
    p.display(); // Output: (2, 6)

    return 0;
}

