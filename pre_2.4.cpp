/*A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's
management sought to build a system that could keep track of individual items, including details like
a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.
To address this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of item details, either with default values or
specific attributes like ID, name, price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when items were sold,
ensuring sufficient inventory was available for each transaction. Additionally, the system would
provide clear, detailed summaries of each item's status, aiding in decision-making and reporting.
The developers faced real-world scenarios where they had to manage multiple inventory items
simultaneously. They planned to design an array of inventory items and simulate common tasks such
as adding stock, processing sales transactions, and displaying the current inventory details. Handling
edge cases, such as attempting to sell more items than available in stock, became a critical part of the
implementation to ensure reliability.*/
#include <iostream>
using namespace std;

class InventoryItem {
private:
    int itemID;
    string itemName;
    float price;
    int quantity;

public:
    InventoryItem() {
        itemID = 0;
        itemName = "Default Item";
        price = 0.0;
        quantity = 0;
    }

    InventoryItem(int id, string name, float itemPrice, int stockQuantity) {
        itemID = id;
        itemName = name;
        price = itemPrice;
        quantity = stockQuantity;
    }

    void addStock(int amount) {
        quantity += amount;
    }

    void sellItem(int amount) {
        if (amount <= quantity) {
            quantity -= amount;
        } else {
            cout << "Insufficient stock to complete the sale." << endl;
        }
    }

    void displayItemDetails() {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity in Stock: " << quantity << endl;
    }
};

int main() {
    InventoryItem items[3];

    items[0] = InventoryItem(101, "Laptop", 1000.50, 30);
    items[1] = InventoryItem(102, "phone", 500.75, 50);
    items[2] = InventoryItem(103, "Headphones", 150.25, 100);

    for (int i = 0; i < 3; i++) {
        items[i].displayItemDetails();
    }

    items[0].addStock(20);
    items[1].sellItem(10);
    items[2].sellItem(150);


    for (int i = 0; i < 3; i++) {
        items[i].displayItemDetails();
    }

    return 0;
}

