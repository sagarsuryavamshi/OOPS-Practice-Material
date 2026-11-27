// Try to throw the exception by calling fuction in try block
#include <iostream>
using namespace std;

void divide(int a, int b){
    if(b==0){
        throw "Division by zero error"; // Throwing an exception when dividing by zero
    }
    int c = a/b;
    cout << "Division -> " << c << endl ;
}
int main(){
    int a ;
    int b ;
    cin >> a >> b ;
    try{
        divide(a,b);
    }
    catch(...){
        cout << "Caught generalised error" << endl ;
    }
}
// why do we add const char* in catch block?
// We add const char* in the catch block because the exception being thrown is a string literal,
// which is of type const char*. By catching it as const char*, we can handle the exception
// can you explain the const char* in catch block in more detail?
// Certainly! In C++, when you throw an exception using a string literal (like "Division by zero error"), the type of that literal is `const char*`. This means it is a pointer to a constant character array (the string).