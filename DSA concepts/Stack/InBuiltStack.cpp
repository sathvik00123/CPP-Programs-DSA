#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    cout<<"size "<<s.size()<<endl;
    cout<<"top "<<s.top()<<endl;
    s.pop();
    cout<<"top "<<s.top()<<endl;
    s.pop();
    cout<<"top "<<s.top()<<endl;
    s.pop();

    cout<<"size "<<s.size()<<endl;
    cout<<"empty "<<s.empty()<<endl;

    while(!s.empty()){
        cout<<"top "<<s.top()<<endl;
        s.pop();
    }
    s.pop();
    return 0;
}