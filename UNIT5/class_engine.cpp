// Engine class implementation outside the class definition
#include <iostream>
using namespace std;

class Engine {
public:
    Engine() { // Constructor created
        cout << "Engine created" << endl; // Output message when an Engine object is created
    }
    ~Engine() { // Destructor created
        cout << "Engine destroyed" << endl; // Output message when an Engine object is destroyed
    }
};
class Car {
    Engine* e; // Pointer to an Engine object
public:
    Car() { // Constructor created
        cout << "Car created" << endl; // Output message when a Car object is created           
        e = new Engine(); // Dynamically allocate an Engine object 
    }
    ~Car() { // Destructor created
        cout << "Car destroyed" << endl; // Output message when a Car object is destroyed
        delete e; // Deallocate the Engine object, calling the destructor
        e = nullptr; // Set the pointer to nullptr after deletion to avoid dangling pointer
    }
};

int main() {
    Car c; // Create a Car object, which will create an Engine object
    return 0;
}