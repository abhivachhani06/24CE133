/*A financial analytics firm is designing a data processing system to filter out duplicate transaction IDs
from large datasets. The system must take an input list of integers, efficiently remove duplicates, and
display the unique values in an ordered manner. Given the need for high performance in handling
large datasets, the implementation must leverage efficient data structures that automatically
eliminate redundancy.
To achieve this, the system employs an associative container that inherently ensures uniqueness while
maintaining a sorted order. As integers are added, duplicate entries are automatically discarded,
eliminating the need for explicit duplicate-checking logic. Once the unique values are identified, they
are either displayed directly using iterators or converted back into a dynamically managed sequence
for further processing.
By utilizing iterators, the system efficiently traverses the filtered dataset, ensuring that unique
elements are accessed and displayed without additional computational overhead.*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void removeDuplicates(const vector<int>& transactions) {
    set<int> uniqueTransactions(transactions.begin(), transactions.end());

    // Display the unique transactions (sorted by default)
    for (const int& transaction : uniqueTransactions) {
        cout << transaction << " ";
    }
    cout << endl;
}

int main() {
    vector<int> transactions = {101, 102, 101, 103, 105, 102, 106};

    cout << "Unique Transaction IDs: ";
    removeDuplicates(transactions);

    return 0;
}

