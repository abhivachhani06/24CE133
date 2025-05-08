/*A mathematical research group aimed to create a software model for handling and performing
operations on complex numbers efficiently. To achieve this, they designed a Complex class that
encapsulates the real and imaginary parts of a complex number. The class supports essential operator
overloading to enhance usability, including the addition and subtraction of complex numbers and
custom input and output functionality through the << and >> operators. These overloaded operators
ensure seamless arithmetic and user interaction with the system.
The task involves implementing this system and exploring its capabilities by performing various
operations on complex numbers. Participants are expected to overload the specified operators and
use them to add and subtract complex numbers, as well as to facilitate user-friendly input and output.
Additionally, the solution encourages experimenting with managing collections of complex numbers
to perform batch operations.*/
#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Constructor with default values
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload >> operator for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) out << " + " << c.imag << "i";
        else out << " - " << -c.imag << "i";
        return out;
    }
};

int main() {
    // Vector to store complex numbers
    vector<Complex> numbers;
    int n;

    cout << "Enter number of complex numbers: ";
    cin >> n;

    // Input complex numbers
    for (int i = 0; i < n; ++i) {
        Complex temp;
        cout << "Complex number " << i + 1 << ":\n";
        cin >> temp;
        numbers.push_back(temp);
    }

    // Batch addition of all complex numbers
    Complex sum;
    for (const Complex& c : numbers) {
        sum = sum + c;
    }

    cout << "\nSum of all complex numbers: " << sum << endl;

    // Optional: demonstrate subtraction of first two (if at least 2)
    if (n >= 2) {
        Complex diff = numbers[0] - numbers[1];
        cout << "Difference of first two complex numbers: " << diff << endl;
    }

    return 0;
}

