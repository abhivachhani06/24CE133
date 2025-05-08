/*A team of developers is tasked with building a temperature conversion system for a weather
application. To achieve this, the team creates two classes: Celsius and Fahrenheit. These classes
handle the conversion between temperature units, with the ability to convert from Celsius to
Fahrenheit and vice versa using type conversion. The team utilizes operator overloading to define the
conversion operators for both classes, enabling seamless conversions between the two units.
The system also requires the ability to compare two temperature objects to check if they are equal.
This is achieved by overloading the equality operator ==, which compares the values of the
temperatures in their respective units.
To ensure smooth processing of temperature conversions, the team needs to manage and store
multiple converted temperature objects. Two approaches are considered for handling this task. The

first approach involves using a dynamic data structure, a queue, to process the conversions in a first-
in-first-out (FIFO) manner. Alternatively, a basic array is used to store the converted objects in a static

manner.*/
#include <iostream>
#include <queue>
using namespace std;

// Class to represent Celsius temperature
class Celsius {
private:
    double temperature;
public:
    Celsius(double temp = 0) : temperature(temp) {}

    // Type conversion operator to convert Celsius to Fahrenheit
    operator double() const {
        return (temperature * 9/5) + 32;
    }

    // Overload equality operator to compare Celsius objects
    bool operator==(const Celsius& other) const {
        return temperature == other.temperature;
    }

    // Getter method for Celsius temperature
    double getTemperature() const {
        return temperature;
    }
};

// Class to represent Fahrenheit temperature
class Fahrenheit {
private:
    double temperature;
public:
    Fahrenheit(double temp = 0) : temperature(temp) {}

    // Type conversion operator to convert Fahrenheit to Celsius
    operator double() const {
        return (temperature - 32) * 5/9;
    }

    // Overload equality operator to compare Fahrenheit objects
    bool operator==(const Fahrenheit& other) const {
        return temperature == other.temperature;
    }

    // Getter method for Fahrenheit temperature
    double getTemperature() const {
        return temperature;
    }
};

// Function to perform temperature conversion and manage objects using a queue
void manageTemperatureConversions() {
    queue<Celsius> celsiusQueue;
    queue<Fahrenheit> fahrenheitQueue;

    // Add some temperatures to the queue
    celsiusQueue.push(Celsius(25));  // Celsius temperature
    fahrenheitQueue.push(Fahrenheit(77)); // Fahrenheit temperature

    // Convert and print temperatures
    while (!celsiusQueue.empty()) {
        double fahrenheitTemp = celsiusQueue.front();
        cout << "Celsius to Fahrenheit: " << fahrenheitTemp << "F" << endl;
        celsiusQueue.pop();
    }

    while (!fahrenheitQueue.empty()) {
        double celsiusTemp = fahrenheitQueue.front();
        cout << "Fahrenheit to Celsius: " << celsiusTemp << "C" << endl;
        fahrenheitQueue.pop();
    }
}

int main() {
    manageTemperatureConversions();
    return 0;
}

