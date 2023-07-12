#include<iostream>
#include "student_01.cpp"
using namespace std;

int main(){
    student s1(10,100);
    student s2(20,200);
    student *s3 = new student(30,300);

    //copy assignment operator.
    s2 = s1;
    *s3 = s1;
    s1 = *s3;

    delete s3;
    return 0;
}