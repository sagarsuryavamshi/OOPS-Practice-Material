#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std ;
int main(){
    ofstream writeStream("HelloWorld.txt");
    writeStream<<"Hello World"<<endl;
    writeStream<<"This is OOPS class"<<endl;
    writeStream<<"We are working on file handling right now!"<<endl;
    writeStream.close();

    ifstream readStream("HelloWorld.txt");
    string s;
    while(getline(readStream, s)){
        cout<<s<<endl;
    }
    readStream.close();
    return 0;
}