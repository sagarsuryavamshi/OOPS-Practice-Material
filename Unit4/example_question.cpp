// implemeting inheritance C is the main it has two child a and B also a has another child e and b has another child d
#include<iostream>
using namespace std;
class C{
    public:
    string color;
    int age;
};
class A: public C{
    public:
    int year;

};
class B: public C{
    public:
    int real ;
    int imag ;
}
class E: public A{

};
class D: public D{

};