// C++ program to demonstrate the order of constructor and destructor calls.
#include<iostream>
using namespace std;
class Example{
    string name;
    public:
    Example(string name): name(name) {
        cout<<name<<" is the name " << endl;
    }
    ~Example(){
        cout<<name<<" object was is being destroyed " << endl;
    }
};
Example e("Global") ;
int main(){
    cout<<"Main"<<endl;
    static Example e1("Static main e1");
    Example e2("Local main e2");
    static Example e3("Static main e3");
    Example e4("Local main e4");
    cout<<"Main destroyed"<<endl; 
    return 0;
}