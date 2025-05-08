/*An educational institution requires a system to generate well-structured student performance reports
from raw data stored in a file. The system should read student records, including their name, marks,
and grade, and present the information in a neatly formatted tabular format. Since the institution

handles large datasets, the report generation must be efficient, ensuring clear alignment and
readability while allowing for future enhancements such as sorting and filtering.
To achieve this, the system must first handle file input operations, reading student data while ensuring
error handling if the file is missing or inaccessible. The program should then format and display the
information in a structured manner, making use of a user-defined manipulator to align columns
properly. This ensures that names, marks, and grades are clearly visible in the report, regardless of
data length variations.
For implementation, two approaches are explored. The first method processes the data directly from
the file, formatting and displaying each entry without storing it in memory. This minimizes memory
usage but limits additional processing, such as sorting or filtering. The alternative approach
dynamically stores student records using a manually managed data structure, allowing further
modifications, such as sorting by marks or filtering based on grades, before presenting the final
formatted report.*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
    char name[50];
    int marks;
    char grade;
};

// Custom manipulator for formatting currency values
ostream& currency(ostream& out) {
    return out << "₹";
}

// Function to read and display student performance report
void generateReport(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << setw(20) << left << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << "-------------------------------------------" << endl;

    while (file >> student.name >> student.marks >> student.grade) {
        cout << setw(20) << left << student.name
             << setw(10) << student.marks
             << setw(10) << student.grade << endl;
    }

    file.close();
}

int main() {
    generateReport("students.txt");
    return 0;
}

