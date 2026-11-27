#include <iostream>
using namespace std ;

int main(){
    int a;
    int b ;
    cin >> a >> b ;
    try{
        if(b==3.14){
            throw "A" ;
        }

        int c = a/b ;
        cout << "Division -> " << c << endl ;
    }
    catch(int i){
        cout << "Caught zero exception error" << endl ;
    }
    catch(double d){
        cout << "Caught double exception error" << endl ;
    }
    catch(...){
        cout << "Caught genealised error" << endl ;
    }
}
// which concept is used in exception handling?
// The concept used in exception handling is the try-catch mechanism, which allows you to handle exceptions that may occur during program execution. It involves wrapping potentially error-prone code in a try block and catching specific exceptions in catch blocks to handle them appropriately.