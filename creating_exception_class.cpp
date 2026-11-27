// ccreatea a exception class having children as follows ArithemeticExcpetion, InvalidDataTypeException, SQLException, MemoryOverflowException. and divide it by 0. by creating a abstract class for Exception.
#include <iostream>
using namespace std;

class Exception{
    public:
    virtual void print() = 0;

};
class ArithmeticException : public Exception{
    public:
    void print(){
        cout << "Arithmetic Exception: Exception caught !" << endl;
    }
};
class InvalidDataTypeException : public Exception{
    public:
    void print(){
        cout << "Invalid Data Type Exception: Invalid data type error" << endl;
    }
};
class SQLException : public Exception{
    public:
    void print(){
        cout << "SQL Exception: Database error" << endl;
    }
};
class MemoryOverflowException : public Exception{   
    public:
    void print(){
        cout << "Memory Overflow Exception: Memory overflow error" << endl;
    }
};
int main(){
    int a;
    int b;
    cin >> a >> b;
    try{
        if(b==0){
            throw new ArithmeticException(); // Throwing ArithmeticException when dividing by zero
        }
        int c = a/b;
        cout << "Division -> " << c << endl;
    }
    catch(ArithmeticException *e){ // Catching ArithmeticException //why are we using pointer here? because we are throwing a new object of ArithmeticException, so we need to catch it as a pointer.
        e->print();
    }
}
// which is the most import concept in exception handling? The most important concept in exception handling is to catch exceptions properly and handle them gracefully, ensuring that the program can recover or terminate safely without crashing.