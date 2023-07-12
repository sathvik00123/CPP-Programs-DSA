// In software development this is called "isolation of logic"....(IOL) it is nothing but creating the classes
// in other program file.
#include<iostream>
using namespace std;

class student{

    int age;

public:
    int roll;
    //destructor
    ~student(){
        cout<<"this is a destructor for object."<<endl;
    }
    // defualt constructor
    student(){
        cout<<"this is a defualt constructor"<<endl;
    }
    //parameterised constructor
    student(int r){
        cout<<"this is a parameterised constructor"<<endl;
        this->roll = roll; //this here is mandatory.
    }
    //another parameterised constructor
    student(int a,int r){
        cout<<"this :"<<this<<endl;
        cout<<"this is a parameterised constructor"<<endl;
        this->roll = r; ///this optional
        this->age = a;  /// this optional 
    }
    void display(){
        cout<<age<<" "<<roll<<endl;
    }
    int getAge(){
        return age;
    }
    void setAge(int a){
        if(a>0){
            return;
        }
        age = a;
    }
};