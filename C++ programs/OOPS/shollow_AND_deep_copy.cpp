#include<iostream>
#include<cstring>
using namespace std;
class student{
    int age;
    char *name;

    public:
    student(int age,char *name){
        this->age = age;
        // this->name = name;    shollow copy...

        // deep copy...
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    void display(){
        cout<<age<<" "<<name<<endl;
    }
};
int main(){
    char name[] = "abcd";
    student s1(10,name);
    s1.display();

    name[3] = 'e';
    student s2(20,name);
    s2.display();

    s1.display();
    return 0;
}