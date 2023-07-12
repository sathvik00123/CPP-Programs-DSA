#include<iostream>
#include "student_01.cpp"
using namespace std;

int main(){
    // creating a object statically.
    student s1;
    student s2;
    student s3,s4,s5;

    //creating an object dynamically.
    student *s6 = new student;

    // s1.age = 34;
    s1.roll = 92;
    s1.display();
    s2.display();

    // (*s6).age = 34;
    (*s6).roll = 92;
    (*s6).display();
    //(or)
    // s6->age = 34;
    s6->roll = 92;
    s6->display();

    // cout<<s1.age<<endl;
    cout<<s1.roll<<endl;
    // cout<<(*s6).age<<endl;
    cout<<s6->roll<<endl;
    return 0;
}

