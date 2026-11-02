// Program to demonstrate the use of constructor with initializer list in C++.
#include<iostream>
using namespace std; 
class Employee{
    int employee_id;
    string employee_name;
    public:
    // Employee(int employee_id, string employee_name){
    //     this->employee_id = employee_id;
    //     this->employee_name = employee_name;
    // }
    Employee(int employee_id, string employee_name): employee_id(employee_id), employee_name(employee_name) {
        cout<<"Called Parameterized constructor called for Employee ID "<< employee_id << endl;
    }
    ~Employee(){
        cout<<"Destructor called for Employee ID: " << employee_id << endl;
    }

};
int main(){
    Employee emp(1, "John Doe");
    Employee emp2(2, "Jane Smith");
    Employee emp3(3, "Alice Johnson");
    return 0;
}
