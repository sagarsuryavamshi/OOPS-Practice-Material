// Make an abstract class vehicle with a pure virtual functions start() and stop().
// Make 2 derived classes car and bike.
#include <iostream>
using namespace std;

class Vehicle{
public:
    Vehicle(){
        cout << "Vehicle OBJECT is being created..." << endl; } // Default constructor
    virtual void start() = 0; // Pure virtual function for starting the vehicle
    virtual void stop() = 0; // Pure virtual function for stopping the vehicle
    virtual ~Vehicle() {}  // Virtual destructor to ensure proper cleanup of derived class objects
};

class Car : public Vehicle{ 
public:
    void start() override{ //Override the start function for car
        cout << "Car is starting..." << endl;
    }
    void stop(){ // if ovverride is not used, it will still override the base class function, but using override is a good practice to catch errors at compile time.
        cout << "Car is stopping..." << endl;
    }
};

class Bike : public Vehicle{ // Derived class Bike from Vehicle 
public:
    void start() override{
        cout << "Bike is starting..." << endl;
    }
    void stop() override{
        cout << "Bike is stopping..." << endl;
    }
};
int main(){
// We cannot create an object of the abstract class Vehicle, but we can create pointers of type Vehicle and point them to derived class objects.
    Vehicle* v1 = new Car(); // Create a Car object
    v1->start(); // Call start() on Car
    v1->stop(); // Call stop() on Car
    delete v1; // Clean up

    Vehicle* v2 = new Bike(); // Create a Bike object
    v2->start(); // Call start() on Bike
    v2->stop(); // Call stop() on Bike
    delete v2; // Clean up

    return 0;
}