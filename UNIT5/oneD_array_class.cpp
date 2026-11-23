// creating a 1D array class.
#include <iostream>
using namespace std;
class OneDArray {
    int* arr; // Pointer to the array
    int size; // Size of the array
public:
    // Constructor to initialize the array with a given size
    OneDArray(int s) : size(s) { // Initialize the size
        arr = new int[size]; // Dynamically allocate memory for the array
        cout << "Array of size " << size << " created." << endl;
        for (int i=0;i<size ;i++){
            arr[i] =0;
        }
        cout << "Array initialized with zeros." << endl;
    }
    void display() const { // Function to display the array elements
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " "; // Print each element
        }
        cout << endl;
    }
    ~OneDArray() { // Destructor to free the allocated memory
        delete[] arr; // Free the dynamically allocated memory
        arr = nullptr; // Set the pointer to nullptr to avoid dangling pointer
        cout << "Array of size " << size << " destroyed." << endl;
    }
};
int main() {
    OneDArray arr(5); // Create an instance of OneDArray with size 5
    arr.display(); // Display the array elements
    return 0; // The destructor will be called automatically when arr goes out of scope
}