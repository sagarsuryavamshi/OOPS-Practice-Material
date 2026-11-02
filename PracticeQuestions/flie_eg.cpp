#include<iostream>
#include<fstream>
using namespace std ;
int main(){
    ofstream writeStream("The Flamingo.txt") ;
    writeStream << "THis is a engligh text book CLass XII." << endl ;
    writeStream <<"This text book has interesting stories. " << endl ;
    writeStream << "This book perfect for story readers." << endl ; 
    writeStream.close() ;

    ifstream readStream("The Flamingo.txt") ;
    string s ;
    while(getline(readStream, s)){
        cout<<s<<endl ;

}
}