/*In a rapidly growing software development firm, a team of engineers is tasked with building a
lightweight, custom memory management system for handling dynamic datasets. The existing
framework lacks flexibility in managing arrays, often leading to inefficient memory usage and
performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at
the end of the dataset and removing specific elements based on their position. Since the system
operates in a resource-constrained environment, using standard template libraries is not an option,
and direct dynamic memory management must be implemented using pointers. The solution should
ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary
overhead.
The development team must carefully decide on the structure of their implementation, defining how
data will be stored, accessed, and modified efficiently. They need to outline the appropriate class
design, determine essential data members, and define necessary member functions to handle the
operations effectively.*/
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

public:
    // Constructor to initialize the array with a given capacity
    DynamicArray(int initial_capacity = 5) : capacity(initial_capacity), size(0) {
        arr = new int[capacity]; // Allocate memory dynamically
    }

    // Destructor to free dynamically allocated memory
    ~DynamicArray() {
        delete[] arr; // Free memory
    }

    // Resize the array when capacity is reached
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr; // Free the old array
        arr = newArr; // Point to the new array
    }

    // Add element at the end of the array
    void addElement(int value) {
        if (size == capacity) {
            resize(); // Resize if needed
        }
        arr[size++] = value;
    }

    // Remove element from a specific position
    void removeElement(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1]; // Shift elements to the left
            }
            size--;
        }
    }

    // Display the array
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    arr.addElement(10);
    arr.addElement(20);
    arr.addElement(30);
    arr.addElement(40);
    arr.addElement(50);
    arr.display(); // Output: 10 20 30 40 50

    arr.removeElement(2); // Remove element at index 2
    arr.display(); // Output: 10 20 40 50

    return 0;
}

