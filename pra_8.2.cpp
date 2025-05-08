/*A digital publishing company is developing a tool to analyze text content for word frequency
distribution. This tool aims to help writers and editors understand the prominence of specific words
in an article, enabling them to refine their content for clarity and impact. The system should process
an input sentence, count occurrences of each unique word, and display the results in an organized
manner.
To achieve this, the system utilizes an associative container that maps words to their corresponding
frequencies. As the text is processed, each word is extracted and stored as a key, while its occurrence
count is maintained as the associated value. By leveraging iterators, the system efficiently traverses
the data structure, displaying each word along with its computed frequency.
The use of a dynamic mapping approach ensures that words are stored in an ordered manner, allowing
for fast retrieval and structured output.*/
    #include <iostream>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;

void countWordFrequency(const string& sentence) {
    map<string, int> wordFrequency;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        // Convert word to lowercase
        for (char& c : word) {
            c = tolower(c);
        }
        wordFrequency[word]++;
    }

    // Display the frequency of each word
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string sentence = "This is a test. This test is simple!";
    countWordFrequency(sentence);
    return 0;
}

