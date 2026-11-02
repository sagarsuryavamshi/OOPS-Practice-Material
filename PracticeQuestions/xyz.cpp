#include<iostream>
#include<iomanip>
using namespace std ;
int calculateFinalVelocity(double *u, double *a, int *t, double *v){
    double velicity = *u + (*a) * (*t) ;
    double distance = (*u) * (*t) + 0.5 * (*a) * (*t) * (*t) ;
    cout<<fixed<<setprecision(2)<<endl;
    cout<<"Final Velocity-> "<<velicity<<endl;
    cout<<"Distance-> "<<distance<<endl;
    return 0;
}
int main(){
    double u, a,v;
    int t ;
    cin>>u>>a>>t ;
    calculateFinalVelocity(&u, &a, &t, &v);
}