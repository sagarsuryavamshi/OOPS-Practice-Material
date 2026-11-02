// DO operator overloading of a weight class for operators binary + Weight w = a+b, ++ increase weight by 100 grams.
#include <iostream>
using namespace std;
class Weight{
    public:
    int kg;
    int g;
    Weight(int k=0, int g=0){
        this->kg=k;
        this->g=g;
    };
    Weight operator+(Weight w){
        Weight temp;
        temp.kg=this->kg+w.kg;
        temp.g=this->g+w.g;
        if(temp.g>=1000){
            temp.kg+=temp.g/1000;
            temp.g=temp.g%1000;
        }
        return temp;
    }
    Weight operator++(){
        this->g+=100;
        if(this->g>=1000){
            this->kg+=this->g/1000;
            this->g=this->g%1000;            
        }
        return *this;
    }
};
int main(){
    Weight w1(2,5000), w2(3,800);
    Weight w3=w1+w2;
    cout<<"Weight 1: "<<w1.kg<<" kg "<<w1.g<<" g"<<endl;
    cout<<"Weight 2: "<<w2.kg<<" kg "<<w2.g<<" g"<<endl;
    cout<<"Weight 3: "<<w3.kg<<" kg "<<w3.g<<" g"<<endl;
    ++w1;
    cout<<"Weight 1 increment: "<<w1.kg<<" kg "<<w1.g<<" g"<<endl;
    ++w2;
    cout<<"Weight 2 increment: "<<w2.kg<<" kg "<<w2.g<<" g"<<endl;
    ++w3;
    cout<<"Weight 3 increment: "<<w3.kg<<" kg "<<w3.g<<" g"<<endl;
    return 0 ;
}