#include<iostream>
#include "student_01.cpp"
using namespace std;
int main(){
    student s1;
    student *s2 = new student;

    cout<<s1.getAge()<<endl;
    cout<<s2->getAge()<<endl;
    

    s1.setAge(134);
    s2->setAge(143);

    s1.display();
    s2->display();

    return 0;
}