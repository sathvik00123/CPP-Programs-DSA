#include<iostream>
using namespace std;
class student{
    public:
    int age;
    const int rollnum;
    
    student(int r,int age) : rollnum(r),age(age){
    }
};
int main(){
    student s1(120,22);
    cout<<s1.age<<" "<<s1.rollnum<<endl;
    return 0;
}