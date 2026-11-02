// Opreator overloading example
#include<iostream>
using namespace std ;

class ComplexNum{
    int real ;
    int imag ;
    public:
    ComplexNum(int r,int i): real(r),imag(i) {
        cout << "Complex number created: " << endl ;
    }
    ComplexNum operator+(const ComplexNum &other)const{
        ComplexNum c(0,0) ;
        c.real = real + other.real ;
        c.imag = imag + other.imag ;
        return c ;
    }
    void display()const{
        cout << real<<"+"<< imag <<"i" << endl ;
    }
} ;
int main(){
    ComplexNum a(10,3) ;
    ComplexNum b(4,20) ;
    ComplexNum c = a + b ;
    c.display() ;
    return 0 ;
}