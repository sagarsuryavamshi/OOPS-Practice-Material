// creting a shared pointer using weak pointer
#include <iostream>
#include <memory> // Include the memory header for smart pointers
using namespace std;

int main(){
    shared_ptr<int> ptr1 = make_shared<int>(10); // Create a shared pointer to an integer with value 10
    weak_ptr<int> ptr2 = ptr1; // Create a weak pointer from shared pointer
    if(shared_ptr<int> temp = ptr2.lock()){ // Lock the weak pointer to create a shared pointer
        cout << "Value: " << *temp << endl; // Access the value through the shared pointer
    } else {
        cout << "No pointers there!" << endl; // If the shared pointer has expired, this block will execute
    }
}