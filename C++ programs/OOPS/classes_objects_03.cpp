#include<iostream>
#include "student_01.cpp"
using namespace std;
int main(){
    student s1;
    s1.display();

    student s2;
    s2.display();

    student *s3 = new student;
    s3->display();

    student s4(20);
    s4.display();

    student *s5 = new student(100);
    s5->display();

    student s6(10,100);
    s6.display();

    return 0;
}