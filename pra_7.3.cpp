/*A small retail business is looking for a simple yet effective inventory management system to keep track
of its products. The system needs to support essential operations such as adding new items, viewing
the complete inventory, and searching for specific products. Since the inventory data should persist
across sessions, all operations must be performed using file storage. The business also requires an
efficient way to retrieve item details without unnecessary file reads.
To manage inventory, the system must allow employees to add new products by recording details
such as the item name, quantity, and price. These records should be appended to a file, ensuring that
previously stored data remains intact. When viewing inventory, the system should read the file
sequentially and display all stored items. Additionally, employees should be able to search for a
product by name, retrieving its details without manually scanning the entire file.
For implementation, two approaches are considered. One method processes file operations directly,
reading and searching line by line to retrieve item information efficiently. This minimizes memory
usage but requires re-reading the file for each search operation. An alternative approach loads
inventory data into a dynamically managed array, enabling faster searches*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Product {
    char name[50];
    int quantity;
    double price;
};

// Function to add a product to the file
void addProduct(const char* filename, const Product& product) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Unable to open file!" << endl;
        return;
    }
    file << product.name << " " << product.quantity << " " << product.price << endl;
    file.close();
}

// Function to view all products in the file
void viewInventory(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file!" << endl;
        return;
    }

    Product product;
    while (file >> product.name >> product.quantity >> product.price) {
        cout << "Name: " << product.name << ", Quantity: " << product.quantity << ", Price: " << product.price << endl;
    }
    file.close();
}

// Function to search for a product by name
void searchProduct(const char* filename, const char* productName) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file!" << endl;
        return;
    }

    Product product;
    while (file >> product.name >> product.quantity >> product.price) {
        if (strcmp(product.name, productName) == 0) {
            cout << "Found: " << product.name << ", Quantity: " << product.quantity << ", Price: " << product.price << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
    file.close();
}

int main() {
    Product p1 = {"Apple", 50, 0.75};
    addProduct("inventory.txt", p1);
    viewInventory("inventory.txt");
    searchProduct("inventory.txt", "Apple");
    return 0;
}

