// Class Animal 
#include <iostream>
#include <string>
using namespace std;
class Animal {
    public:
    string color;
    int age;
    Animal(){
        cout << "Animal created!!." << endl;
    }
    virtual ~Animal() = default;
    virtual void sleep(){
        cout << "Animal is sleeping!!." << endl;
    }
    virtual void eat() {
        cout << "Animal is eating!!." << endl;
    }
};
class Dog:  public Animal {
    public:
    Dog(){
        cout << "Dog Constructor created!!." << endl;
    }
    void sleep(){
        cout << "Dog is sleeping!!." << endl;
    }
    void eat(){
        cout << "Dog is eating!!." << endl;
    }
    void wagsTail(){
        cout << "Dog is wagging its tail!!." << endl;
    }
};
int main() {
    Dog d;
    Animal &a = d; // Upcasting
    a->sleep(); // This will call Dog's sleep() because of virtual function
    a->getdata
    //a->eat(); // This will call Dog's eat() because of virtual function
    // d.wagsTail(); // This will call Dog's wagsTail()
    // d.sleep(); // This calls Dog's public sleep() implementation.
    return 0;
}