// creating a 2D array in C++
#include <iostream>
using namespace std;
class TwoDArray {
    int** arr; // Pointer to a pointer for the 2D array
    int rows; // Number of rows in the 2D array
    int cols; // Number of columns in the 2D array
public:
    // Constructor to initialize the 2D array with given rows and columns
    TwoDArray(int r, int c) : rows(r), cols(c) { // Initialize rows and columns
        arr = new int*[rows]; // Dynamically allocate memory for rows
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols]; // Dynamically allocate memory for columns in each row
        }
        cout << "2D Array of size " << rows << "x" << cols << " created." << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = 0; // Initialize each element to zero
            }
        }