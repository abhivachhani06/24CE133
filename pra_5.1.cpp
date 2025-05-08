/*A software development team aimed to design a versatile utility that could perform basic arithmetic

operations while demonstrating the concept of function overloading. This effort resulted in a class-
based calculator system capable of handling various combinations of input types, such as integers and

floating-point numbers. The system includes multiple overloaded add functions, each tailored to
accept distinct input types and perform addition operations accordingly. This approach ensures the
calculator is adaptable and provides consistent functionality regardless of the input types.
The case revolves around testing and validating the versatility of this calculator. Participants are
expected to create instances of the calculator, invoke the appropriate overloaded functions for various
input scenarios, and store the resulting values for further analysis. To organize and display these
results, the system incorporates methods to sequentially process and present the outcomes.*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Calculator {
private:
    vector<string> results; // Stores formatted results

public:
    // Add two integers
    int add(int a, int b) {
        int res = a + b;
        results.push_back("add(int, int): " + to_string(res));
        return res;
    }

    // Add two floats
    float add(float a, float b) {
        float res = a + b;
        results.push_back("add(float, float): " + to_string(res));
        return res;
    }

    // Add int and float
    float add(int a, float b) {
        float res = a + b;
        results.push_back("add(int, float): " + to_string(res));
        return res;
    }

    // Add float and int
    float add(float a, int b) {
        float res = a + b;
        results.push_back("add(float, int): " + to_string(res));
        return res;
    }

    // Display all results
    void displayResults() const {
        cout << "=== Calculation Results ===\n";
        for (const string& r : results) {
            cout << r << endl;
        }
    }
};

int main() {
    Calculator calc;

    // Test cases with different input types
    calc.add(5, 3);           // int + int
    calc.add(4.2f, 2.3f);     // float + float
    calc.add(7, 3.5f);        // int + float
    calc.add(6.7f, 4);        // float + int

    // Display stored results
    calc.displayResults();

    return 0;
}

