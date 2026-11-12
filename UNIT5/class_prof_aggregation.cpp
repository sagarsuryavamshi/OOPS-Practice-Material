#include<iostream>
using namespace std;

class Professor {
    public:
        Professor() { // Constructor created 
            cout << "Professor created with cleared PhD" << endl; // Output message when a Professor object is created
        }
        ~Professor() { // Destructor created
            cout << "Professor destroyed FAILED" << endl;
        }
};
 class University{
    Professor *p; // Pointer to a Professor object
    public:
        University(Professor &other) { // Constructor created
            cout << "University hired professor" << endl; // Output message when a University object is created
            p = &other; // Assign the address of the passed Professor object to the pointer p
        }
        ~University() { // Destructor created
            cout << "University fired professor" << endl; // Output message when a University object is destroyed
        }
 };
 int main(){
    Professor prof; // Create a Professor object
    University u(prof); // Create a University object, passing the Professor object to its constructor
    return 0; // Return 0 to indicate successful execution
 }