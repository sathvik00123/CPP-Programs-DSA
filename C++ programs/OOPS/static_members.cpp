#include<iostream>
using namespace std;
class student{
    public:
    static int totalstudents;
    int age;
    int rollnum;

    student(){
        totalstudents++;
    } 

    int getrollnum(){
        return rollnum;
    }

    static int gettotalstudents(){
        return totalstudents;
    }
    
};

int student::totalstudents = 0;  // initilizing the static members...

int main(){
    cout<<student::gettotalstudents()<<endl;
    student s1,s2,s3,s4,s5;
    cout<<s1.age<<" "<<s1.rollnum<<endl;
    cout<<s1.getrollnum()<<endl;
    cout<<student::totalstudents<<endl;
    cout<<student::gettotalstudents()<<endl;
    return 0;
}