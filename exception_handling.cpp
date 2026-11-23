#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    try {
        if (b == 0) {
            throw 0;
        }

        int c = a / b;
        cout << "Division -> " << c << endl;
    }
    catch (int i) {
        cout << "Caught zero exception error" << endl;
    }
}