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
    // Constructor for Car
    Car(){
        cout << "Car OBJECT is being created..." << endl;
    }
    virtual void Enginestarts() =0; // Pure virtual function for starting the engine, making Car an abstract class as well
    void start() override{ //Override the start function for car
        cout << "Car is starting..." << endl;
    }
    void stop(){ // if ovverride is not used, it will still override the base class function, but using override is a good practice to catch errors at compile time.
        cout << "Car is stopping..." << endl;
    } 
};
class Ford : public Car{ // Derived class Ford from Car
public:
    Ford(){
        cout << "Ford Car created..." << endl; // Constructor for Ford
    }
    void Enginestarts() override{ // Implement the pure virtual function from Car
        cout << "Ford engine is starting..." << endl;
    }
    void stop() override{ //Override the stop function for Ford
        cout << "Ford is stopping..." << endl;
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
    Ford ford; //Create a concrete Ford object on the stack
    Vehicle* v1 = &ford;
    v1->start(); // Call start() on Car
    v1->stop(); // Call stop() on Car

    Bike bike; // Create a Bike object on the stack
    Vehicle* v2 = &bike;
    v2->start(); // Call start() on Bike
    v2->stop(); // Call stop() on Bike
    return 0;
}
//  pure virtual functions need to implemented in the derived classes, otherwise the derived class will also be considered abstract and cannot be instantiated.
//  QUESTION: what if derived class does not implement all pure virtual functions?
//  ANSWER: If a derived class does not implement all pure virtual functions, it will also be considered an abstract class and cannot be instantiated.

// A concrete class deriving an abstract class must be define all the left out pure virtual functions in order to be instantiated. If it does not, it will remain an abstract class and cannot be instantiated.
// what is concrete class?
// A concrete class is a class that has no pure virtual functions and can be instantiated. It provides implementations for all inherited pure virtual functions from its base classes.  
// Pure virtual functions should have at least one definition in any if thier derived classes. If they are not defined, the derived class will also be considered abstract and cannot be instantiated.
