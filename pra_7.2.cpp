/*A data analysis firm is developing a tool to process large text files and extract key statistics, such as
the total number of characters, words, and lines. This tool is essential for tasks like document indexing,
text summarization, and data validation. Given the varying sizes of input files, the system must handle
large datasets efficiently while ensuring error detection when files are missing or inaccessible.
To begin, the program needs to open a specified text file and process its contents line by line. If the
file cannot be found or opened due to permission issues, the system should notify the user with an
appropriate error message and safely terminate execution. Once the file is successfully accessed, the
program will analyze its contents to count the total number of lines, extract words while handling
different delimiters, and compute the total number of characters, including spaces and punctuation.
For handling this data, the team explores two approaches. One approach dynamically stores the lines
in a manually managed array, processing the information without relying on built-in containers. This
requires careful memory allocation and deallocation to avoid leaks. The alternative approach uses a
dynamic structure to hold the lines in memory, allowing for efficient access and further analysis, such
as searching or editing.*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void analyzeFile(const string& filename) {
    ifstream file(filename); // Open file

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl; // Error handling if the file is inaccessible
        return;
    }

    string line;
    int totalLines = 0, totalWords = 0, totalChars = 0;

    // Process the file line by line
    while (getline(file, line)) {
        totalLines++;
        totalChars += line.length();

        // Count words in the line
        istringstream stream(line);
        string word;
        while (stream >> word) {
            totalWords++;
        }
    }

    cout << "Total Lines: " << totalLines << endl;
    cout << "Total Words: " << totalWords << endl;
    cout << "Total Characters: " << totalChars << endl;

    file.close(); // Close file
}

int main() {
    string filename = "sample.txt"; // Provide your file name
    analyzeFile(filename);
    return 0;
}
