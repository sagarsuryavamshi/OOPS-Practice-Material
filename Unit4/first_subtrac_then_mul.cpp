// Oprerator overloading example for first subtract then multiply
#include<iostream>
using namespace std ;

class ComplexNum{
    int real ;
    int imag ;
    public:
    ComplexNum(int real,int imag): real(real),imag(imag) {
        cout << "Complex number created: " << endl ;
    }
    ComplexNum operator-(const ComplexNum &other)const{
        ComplexNum c(0,0) ;
        c.real = real - other.real ;
        c.imag = imag - other.imag ;
        return c ;
    }
    ComplexNum operator*(const ComplexNum &other)const{
        ComplexNum c(0,0) ;
        c.real = real * other.real - imag * other.imag ;
        c.imag = imag * other.real + real * other.imag ;
        return c ;
    }
    void display()const{
        cout << real<<"+"<< imag <<"i" << endl ;
    }
} ;
int main(){
    ComplexNum a(10,3) ;
    ComplexNum b(4,20) ;
    ComplexNum c = a - b ;
    ComplexNum d = c * a ;
    d.display() ;
    return 0 ;
}