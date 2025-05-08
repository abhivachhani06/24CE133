/*A software development team requires a lightweight directory management system to efficiently
organize project files. The system should allow users to create folders, add files to specific folders, and
display the directory structure in an organized manner.
Each folder serves as a unique entry, mapping to a list of associated files, ensuring structured storage
and easy retrieval. A hierarchical mapping approach is used, where folder names act as keys, and
dynamically resizable sequences store the corresponding filenames.
The system provides essential functionalities, including adding new folders, appending files to existing
folders, and displaying the complete directory structure. To enhance accessibility, folder names are
sorted alphabetically, allowing users to quickly locate specific folders and their contents. Iterators are
used for efficient traversal and structured display of data. This approach ensures optimized
performance, even for large datasets, while maintaining a logical and organized hierarchy.*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Directory {
public:
    void addFolder(const string& folderName) {
        directories[folderName] = vector<string>();
    }

    void addFileToFolder(const string& folderName, const string& fileName) {
        if (directories.find(folderName) != directories.end()) {
            directories[folderName].push_back(fileName);
        }
        else {
            cout << "Folder does not exist!" << endl;
        }
    }

    void displayStructure() {
        for (const auto& entry : directories) {
            cout << "Folder: " << entry.first << endl;
            cout << "Files: ";
            for (const string& file : entry.second) {
                cout << file << " ";
            }
            cout << endl;
        }
    }

private:
    map<string, vector<string>> directories; // Maps folder names to files in those folders
};

int main() {
    Directory dir;

    dir.addFolder("Documents");
    dir.addFolder("Images");
    dir.addFileToFolder("Documents", "file1.txt");
    dir.addFileToFolder("Images", "image1.jpg");
    dir.addFileToFolder("Documents", "file2.txt");

    cout << "Directory Structure: " << endl;
    dir.displayStructure();

    return 0;
}

