/*A small retail store is facing challenges in managing its inventory effectively. The store sells a
variety of products, each identified by a unique product ID, a name, the available quantity in
stock, and the price per unit. To streamline their operations, the store needs a basic system to
manage this inventory efficiently.
The system must provide the ability to add new products to the inventory, ensuring that each
product has its ID, name, quantity, and price properly recorded. Additionally, the system should
allow the store staff to update the quantity of any existing product, such as when new stock
arrives or when items are sold.
Another essential feature of the system is the calculation of the total value of all products in
the inventory, which is determined by multiplying the quantity of each product by its price and
summing these values for all products.

The store management is exploring two approaches for this system: a procedural approach and
an object-oriented approach. The goal is to evaluate these approaches by comparing their ease
of implementation, code reusability, and overall complexity.
The system's design and implementation should consider these requirements and provide an
effective solution (either procedural approach or an object-oriented approach) to the store's
inventory management problems.*/
#include <iostream>
using namespace std;

struct Product
{
    int id;
    string name;
    int quantity;
    double price;
};

Product inventory[100];
int productCount = 0;

void addProduct(int id, string name, int quantity, double price)
{
    inventory[productCount].id = id;
    inventory[productCount].name = name;
    inventory[productCount].quantity = quantity;
    inventory[productCount].price = price;
    productCount++;
    cout << "Product added successfully!" << endl;
}

void updateQuantity(int id, int newQuantity)
{
    for (int i = 0; i < productCount; i++)
    {
        if (inventory[i].id == id)
        {
            inventory[i].quantity = newQuantity;
            cout << "Quantity updated successfully!" << endl;
            return;
        }
    }
    cout << "Product not found!" << endl;
}

double calculateTotalValue()
{
    double total = 0;
    for (int i = 0; i < productCount; i++)
    {
        total += inventory[i].quantity * inventory[i].price;
    }
    return total;
}

int main()
{
    int choice;
    while (true)
    {
        cout << "Inventory Management System\n";
        cout << "1. Add a new product\n";
        cout << "2. Update product quantity\n";
        cout << "3. Calculate total value\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            int id, quantity;
            string name;
            double price;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product quantity: ";
            cin >> quantity;
            cout << "Enter product price: ";
            cin >> price;
            addProduct(id, name, quantity, price);
        }

        else if (choice == 2)
        {
            int id, quantity;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter new quantity: ";
            cin >> quantity;
            updateQuantity(id, quantity);
        }

        else if (choice == 3)
        {
            double total = calculateTotalValue();
            cout << "Total value of all products: " << total << endl;
        }

        else if (choice == 4)
        {
            cout << "Exiting...\n";
            break;
        }

        else
        {
            cout << "Invalid choice! Try again.\n";
        }
        cout << endl;
    }
    return 0;
}
