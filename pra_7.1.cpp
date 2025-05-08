/*A media research team is developing a tool to analyze word frequency in large textual datasets, such
as news articles and research papers. The goal is to process a given paragraph, identify individual
words, and count their occurrences while ensuring case-insensitive matching. Since the tool is
intended for both constrained environments and high-performance systems, two different
approaches are considered—one utilizing dynamic memory management and another relying on
manually structured arrays.
The first challenge is reading an entire paragraph from the console as a single unformatted string.
Once acquired, the text must be split into individual words, ensuring that uppercase and lowercase
variations are treated as the same. To store and process words dynamically, the team designs a

mechanism using raw pointers and dynamic memory allocation, allowing the program to handle
variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, with additional logic to count
occurrences efficiently. The array expands as needed, ensuring that new words can be
accommodated. The frequency counting is implemented manually by searching for existing words in
the array and updating counts accordingly.*/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Function to convert a string to lowercase
void toLowerCase(char* word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Word frequency counting function using dynamic memory
void countWordFrequency(const char* paragraph) {
    char* word = new char[100]; // Dynamically allocate memory for word storage
    char* text = new char[strlen(paragraph) + 1];
    strcpy(text, paragraph); // Create a copy of the paragraph
    char* token = strtok(text, " \t\n,.;!?"); // Tokenize based on delimiters

    while (token != nullptr) {
        toLowerCase(token); // Convert each token to lowercase
        bool found = false;
        int i = 0;

        // Search for the token in the word list (array)
        while (i < 100 && word[i] != '\0') {
            if (strcmp(word, token) == 0) {
                found = true;
                break;
            }
            i++;
        }

        // If the word is found, increase its count
        if (!found) {
            cout << token << " found" << endl; // Print new word found
        }
        token = strtok(nullptr, " \t\n,.;!?"); // Move to the next word
    }
    delete[] text;
    delete[] word; // Free dynamically allocated memory
}

int main() {
    const char* paragraph = "This is a simple test. This test is a simple one!";
    countWordFrequency(paragraph);
    return 0;
}

