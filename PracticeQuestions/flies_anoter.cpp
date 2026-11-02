#include<iostream>
#include<fstream>
#include<string>
using namespace std ;

int main(){
    fstream fileStream("Example.txt",ios::in) ;
    string s ;
    while(getline(fileStream,s)){
        cout << s << endl ;
    }
    fileStream.close() ;
    fileStream.open("Example.txt",ios::trunc | ios::out ) ;
    fileStream << "\n Its overwritten by Ghost" ;
    fileStream.close() ;
    return 0 ;
}