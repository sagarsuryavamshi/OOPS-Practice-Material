#include<iostream>
#include<iomanip>
using namespace std ;
class ArrangeArray{
    public:
        double CalculateAverage(int arr[], int n){
            double sum = 0;
            for(int i=0;i<n;i++){
                sum += arr[i];
            }
            return sum/n;
        }
};

int main() {
    int n;
    cin>>n;
    int arr[10];
    for (int i = 0; i < n; i++)
    {
    cin>>arr[i];
    }
    ArrangeArray obj ;
    double avj = obj.CalculateAverage(arr, n);
    cout<<fixed<<setprecision(2)<<avj<<endl;    
	return 0;
}








