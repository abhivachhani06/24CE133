/*A team of software developers was tasked with creating a graphical simulation where operations on
2D points play a crucial role. To facilitate this, they designed a class Point that encapsulates the
coordinates x and y. The class provides flexibility through overloaded operators to manipulate points
efficiently. The unary operator - is overloaded to negate the coordinates of a point, while the binary
operator + enables the addition of two points. Additionally, the equality operator == is overloaded to
compare whether two points have identical coordinates.
The development process required performing various operations between multiple points. To
manage these operations effectively, a mechanism was needed to track and potentially undo them.
This challenge prompted two approaches: using a ready-made dynamic stack structure or building a
custom stack implementation. By managing a sequence of operations in reverse, the stack-based
design allowed for a systematic undo capability, crucial for simulations involving iterative adjustments.*/
#include <iostream>
#include <stack>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Constructor to initialize coordinates
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload unary - to negate the coordinates
    Point operator-() const {
        return Point(-x, -y);
    }

    // Overload binary + to add two points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload equality operator ==
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Display point coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }

    // Accessor methods for x and y
    int getX() const { return x; }
    int getY() const { return y; }
};

class PointOperations {
private:
    stack<Point> history; // Stack to store the history of points

public:
    // Apply operation and store the result in history stack
    void applyOperation(Point p) {
        history.push(p);
    }

    // Undo the last operation by popping from history stack
    void undoOperation() {
        if (!history.empty()) {
            history.pop();
        } else {
            cout << "No operations to undo.\n";
        }
    }

    // Display the current state of the point (top of the stack)
    void displayCurrentState() const {
        if (!history.empty()) {
            history.top().display();
            cout << endl;
        } else {
            cout << "No operations performed.\n";
        }
    }
};

int main() {
    Point p1(3, 4), p2(1, 2), p3(5, 6);
    PointOperations ops;

    // Apply some operations
    ops.applyOperation(p1); // Add first point
    ops.applyOperation(p2); // Add second point

    cout << "Current State: ";
    ops.displayCurrentState();

    // Perform some operations on points
    Point result = p1 + p2; // Add two points
    cout << "After adding points p1 and p2: ";
    result.display();
    cout << endl;
    ops.applyOperation(result);

    // Perform negation operation on a point
    result = -p3; // Negate the coordinates of p3
    cout << "After negating p3: ";
    result.display();
    cout << endl;
    ops.applyOperation(result);

    // Undo last operation (negation)
    cout << "Undoing last operation: ";
    ops.undoOperation();
    ops.displayCurrentState();

    // Undo another operation (addition of p1 + p2)
    cout << "Undoing another operation: ";
    ops.undoOperation();
    ops.displayCurrentState();

    return 0;
}

