// Create a class student Manager with dynamic number of students stored in runtime .
//Your task is to input from the users & display their details.
//number of students should in form of runtime 
#include<iostream>
using namespace std ;
class Student{
    int roll_no ;
    string name ;
    public:
        void input(){
            cout<<"Enter Roll Number: ";
            cin>>roll_no ;
            cout<<"Enter Name: ";
            cin>>name ;
        }
        void display(){
            cout<<"Roll Number: "<<roll_no<<endl ;
            cout<<"Name: "<<name<<endl ;
        }
};
class StudentManager{
    Student *students ;
    int num_students ;
    public:
        StudentManager(int n){
            n
        }