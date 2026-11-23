#include <iostream>
using namespace std ;

int main(){
    int a;
    int b ;
    cin >> a >> b ;
    try{
        if(b==3.14){
            throw "A" ;
        }

        int c = a/b ;
        cout << "Division -> " << c << endl ;
    }
    catch(int i){
        cout << "Caught zero exception error" << endl ;
    }
    catch(double d){
        cout << "Caught double exception error" << endl ;
    }
    catch(...){
        cout << "Caught genealised error" << endl ;
    }
}