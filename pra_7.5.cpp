/*A university administration is developing a system to display student marks in a structured and visually
appealing format. The goal is to ensure clarity in academic reports by properly aligning names and
scores while also demonstrating the use of currency formatting for tuition fees or other financial data.
To achieve this, built-in stream manipulators such as endl, setw, setfill, and setprecision must be used
to create a neatly formatted output.
The system first reads student names and their corresponding marks, ensuring that the data is aligned
in tabular form. Proper spacing between columns enhances readability, preventing misalignment
issues caused by varying name lengths or mark values. Additionally, numerical values must be
displayed with controlled decimal precision for consistency.
Beyond academic scores, the university also wants to format financial figures, such as tuition fees, in
a standardized manner. To achieve this, the system includes a user-defined manipulator, currency(),
which prepends a specified currency symbol (₹, $, etc.) before displaying monetary values. This custom
formatting ensures that financial data is both readable and professionally presented.*/
#include <iostream>
#include <iomanip>
using namespace std;

// Custom manipulator to format financial data
ostream& currency(ostream& out) {
    return out << "$";
}

int main() {
    // Formatting student marks and tuition fees
    cout << setw(15) << left << "Student Name" << setw(10) << "Marks" << setw(10) << "Fees" << endl;
    cout << "--------------------------------------------" << endl;

    // Student data
    cout << setw(15) << left << "John Doe" << setw(10) << 85 << setw(10) << currency << 50000.00 << endl;
    cout << setw(15) << left << "Jane Smith" << setw(10) << 90 << setw(10) << currency << 52000.00 << endl;

    return 0;
}

