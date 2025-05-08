/*A data analytics firm is developing a tool to process numerical sequences efficiently. One of the key
requirements is to reverse a given sequence of integers while ensuring optimized performance using
modern C++ techniques. The system should allow users to input a sequence of numbers, process the
reversal using iterators, and display the transformed output.
To accomplish this, two approaches are explored. The first method leverages the built-in std::reverse()
function, which efficiently reverses elements within a dynamically managed sequence. The second
approach involves manually implementing the reversal using iterators, providing deeper insight into
how iterators navigate and modify data structures.
The system uses a dynamic storage mechanism to handle sequences of varying sizes efficiently.
Iterators facilitate traversal and modification, ensuring that elements are manipulated without direct
indexing.*/
#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;

void reverseWithStdReverse(vector<int>& seq) {
    // Using std::reverse() to reverse the sequence
    std::reverse(seq.begin(), seq.end());
}

void reverseWithIterators(vector<int>& seq) {
    // Manually reversing the sequence using iterators
    auto start = seq.begin();
    auto end = seq.end() - 1;
    while (start < end) {
        swap(*start, *end);
        ++start;
        --end;
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Display original sequence
    cout << "Original sequence: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Reverse using std::reverse
    reverseWithStdReverse(numbers);
    cout << "Reversed using std::reverse: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Reverse using manual iteration
    reverseWithIterators(numbers);
    cout << "Reversed manually with iterators: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

