#include<iostream>
using namespace std;
class Weight{
    int kg;
    int gms;
public:
    Weight(int k, int g):kg(k),gms(g){     // constructor to initialize the weight
    }
    void WeightNormalize(int &temp){       // to normalize the weight
        if(this->gms >= 1000){
            this->gms -= 1000 ;
            temp = 1 ;
        }
    }
    Weight operator+(const Weight &other) const{          // overloading the + operator
        Weight w(0,0);
        int temp = 0 ;
        w.gms = this->gms + other.gms;        // adding the grams of both weights
        if(w.gms >= 1000){
            w.gms -= 1000 ;                   // we can also use the WeightNormalize function here to normalize the weight i.e w.weightNormalize(temp) ;
            w.WeightNormalize(temp) ;         // calling the WeightNormalize function
            temp = 1 ;                        // to add 1 kg to the weight
        }
        w.kg = this->kg + other.kg + temp;    // adding the kg of both weights and the temp value
        return w;
    }
    void operator++(int){          // overloading the ++ operator
        int temp = 0 ;
        this->gms += 100 ;
        this->WeightNormalize(temp) ;         // calling the WeightNormalize function
        this->kg += temp ;                    // adding the temp value to the kg of the weight
    }
    operator double() const{          // overloading the type casting operator
        double kgPart = (double)this->kg ;        // converting the kg to double
        double gmsPart = (double)this->gms/1000.0 ;
        return kgPart + gmsPart ;      // returning the weight in kg
    }
    void displayWeight() const{
        cout<<"Weight: "<<this->kg<<" kg "<<this->gms<<" gms"<<endl;
    }
};
int main(){
    Weight a(1,800);
    Weight b(2,900);
    Weight c = a + b ;
    double d = (double)c ;        // type casting the weight to double
    cout<<"Weight of c in kg: "<<d<<" kg"<<endl;
    cout<<"Weight of a: ";
    a.displayWeight();
    cout<<"Weight of b: ";
    b.displayWeight();
    cout<<"Weight of c: ";
    c.displayWeight();
    a++;                                 // incrementing the weight of a by 100 grams
    cout<<"Weight of a after increment: ";
    a.displayWeight();
    b++;
    cout<<"Weight of b after increment: ";
    b.displayWeight();
}
