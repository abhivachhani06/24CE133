/*A technology firm aimed to develop a flexible and reusable solution for managing collections of various
data types, including integers, floating-point numbers, and characters. The system was intended to
perform fundamental operations on these collections, such as finding the maximum value, reversing
the collection, and displaying all elements. To achieve versatility and avoid redundancy in code, the
solution was designed to use function templates, allowing the same logic to be applied seamlessly to
different data types.
The team recognized the importance of using dynamic arrays to store the collections, enabling
efficient management of varying collection sizes. The design emphasized scalability and flexibility,
ensuring that the system could handle different data types and their associated operations with
minimal changes to the core logic.
In practice, the system allowed for the creation of collections for various data types, such as integers,
floating-point numbers, and characters. The operations on these collections included determining the
maximum value, reversing the order of elements, and printing the collection contents.*/
#include <iostream>
using namespace std;

template <typename T>
class Collection {
private:
    T* data;
    int size;

public:
    Collection(int s) {
        size = s;
        data = new T[size];
    }

    ~Collection() {
        delete[] data;
    }

    void setElement(int index, T value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    T getElement(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return T();
    }

    T findMax() {
        T max = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    void reverse() {
        for (int i = 0; i < size / 2; ++i) {
            T temp = data[i];
            data[i] = data[size - i - 1];
            data[size - i - 1] = temp;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Collection<int> intCollection(5);
    intCollection.setElement(0, 10);
    intCollection.setElement(1, 20);
    intCollection.setElement(2, 5);
    intCollection.setElement(3, 30);
    intCollection.setElement(4, 15);

    cout << "Integer collection: ";
    intCollection.display();
    cout << "Max value: " << intCollection.findMax() << endl;

    intCollection.reverse();
    cout << "Reversed collection: ";
    intCollection.display();

    Collection<float> floatCollection(4);
    floatCollection.setElement(0, 10.5f);
    floatCollection.setElement(1, 20.3f);
    floatCollection.setElement(2, 5.9f);
    floatCollection.setElement(3, 15.7f);

    cout << "Float collection: ";
    floatCollection.display();
    cout << "Max value: " << floatCollection.findMax() << endl;

    floatCollection.reverse();
    cout << "Reversed collection: ";
    floatCollection.display();

    Collection<char> charCollection(3);
    charCollection.setElement(0, 'A');
    charCollection.setElement(1, 'C');
    charCollection.setElement(2, 'B');

    cout << "Char collection: ";
    charCollection.display();
    cout << "Max value: " << charCollection.findMax() << endl;

    charCollection.reverse();
    cout << "Reversed collection: ";
    charCollection.display();
}
