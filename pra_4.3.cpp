/*A vehicle manufacturing company sought to create a robust system to organize and manage the
details of various cars produced under its brand. To accomplish this, a hierarchical structure was
conceptualized, reflecting the essential components of a vehicle. At the foundation, a class was
designed to represent the type of fuel a vehicle uses. Another class was created to capture the brand
name of the vehicle. These two foundational elements were then combined into a derived class
specifically representing cars, integrating both fuel type and brand information.
Constructors were used at each level to ensure proper initialization of attributes, allowing seamless
integration of all details. Additionally, the ability to display complete information about a car, including
its fuel type and brand, was incorporated into the system. To simulate a real-world scenario such as a
service queue, multiple cars were organized and processed sequentially using a structured approach.
This not only streamlined the handling of cars but also provided an opportunity to compare different
methods of managing the collection and processing of vehicle data.*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Base Class: FuelType
class FuelType {
protected:
    string fuel;

public:
    // Constructor with default value
    FuelType(string f = "Unknown") : fuel(f) {}

    // Display fuel type
    void displayFuel() const {
        cout << "Fuel Type: " << fuel << endl;
    }
};


// Base Class: Brand
class Brand {
protected:
    string brandName;

public:
    // Constructor with default value
    Brand(string b = "Generic") : brandName(b) {}

    // Display brand name
    void displayBrand() const {
        cout << "Brand: " << brandName << endl;
    }
};


// Derived Class: Car
// Inherits both FuelType and Brand

class Car : public FuelType, public Brand {
private:
    string model;

public:
    // Constructor initializes FuelType, Brand, and adds model
    Car(string f, string b, string m) : FuelType(f), Brand(b), model(m) {}

    // Display all car information
    void displayCar() const {
        cout << "Model: " << model << endl;
        displayBrand();
        displayFuel();
    }
};


// Static Car Queue Simulation
void staticCarQueue() {
    const int MAX_CARS = 3;  // Static size for simplicity
    Car cars[MAX_CARS] = {
        Car("Petrol", "Toyota", "Corolla"),
        Car("Diesel", "Ford", "Ranger"),
        Car("Electric", "Tesla", "Model 3")
    };

    cout << "\n=== Static Car Queue ===\n";
    for (int i = 0; i < MAX_CARS; ++i) {
        cout << "\nCar " << i + 1 << ":\n";
        cars[i].displayCar();
    }
}


// Dynamic Car Queue Simulation using std::queue

void dynamicCarQueue() {
    queue<Car> carQueue;

    // Enqueue some cars
    carQueue.push(Car("Petrol", "Honda", "Civic"));
    carQueue.push(Car("Diesel", "Chevrolet", "Trailblazer"));
    carQueue.push(Car("Hybrid", "Toyota", "Prius"));

    cout << "\n=== Dynamic Car Service Queue ===\n";

    int count = 1;
    // Process the queue
    while (!carQueue.empty()) {
        cout << "\nCar " << count << ":\n";
        carQueue.front().displayCar(); // Show car info
        carQueue.pop(); // Move to next
        count++;
    }
}


// Main Function

int main() {
    cout << "=== Vehicle Management System ===\n";

    // Simulate static array queue
    staticCarQueue();

    // Simulate dynamic queue using std::queue
    dynamicCarQueue();

    return 0;
}

