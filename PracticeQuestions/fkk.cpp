#include<iostream>
#include<iomanip>
using namespace std ;
void calculateFinalVelocity(void *u, void *a, void *t, z *v){
    double velicity = *u + (*a) * (*t) ;
    double distance = (*u) * (*t) + 0.5 * (*a) * (*t) * (*t) ;
    cout<<fixed<<setprecision(2)<<endl;
    cout<<"Final Velocity-> "<<velicity<<endl;
    cout<<"Distance-> "<<distance<<endl;
}







int main(){
    double u, a,v;
    int t ;
    cin>>u>>a>>t ;
    calculateFinalVelocity(&u, &a, &t, &v);
}