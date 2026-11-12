#include <iostream>
using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine created" << endl;
    }       
    ~Engine() {
        cout << "Engine destroyed" << endl;
    }
};

int main() {
    Engine* engine = new Engine(); // Dynamically allocate an Engine object
    delete engine; // Deallocate the Engine object, calling the destructor
    return 0;
}