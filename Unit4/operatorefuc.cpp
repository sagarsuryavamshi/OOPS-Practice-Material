#include<iostream>
using namespace std ;
class ComplexNum{
    int real ;
    int imag;
    public:
    ComplexNum(int r,int i): real(r),imag(i){
        cout << "Complex. number ceated: " << endl ;
    }
    ComplexNum operator-(const ComplexNum &other)const{
        ComplexNum c(0,0);
        c.real = this->real - other.real ;
        c.imag = this->imag - other.imag ;
        return c ;
    }
    void display()const{
        cout << real<<"+"<<imag<<"i"<<endl;
    }
    ComplexNum operator*(const ComplexNum &other)const{
        ComplexNum c(0,0);
        c.real = this->real * other.real - this->imag * other.imag ;
        c.imag = this->imag * other.real + this->real * other.imag ;
        return c ;
    }
};
int main(){
    ComplexNum a(10,3) ;
    ComplexNum b(4,20) ;
    ComplexNum c = a - b ;
    ComplexNum d = c * a ;
    d.display() ;
    return 0 ;
}