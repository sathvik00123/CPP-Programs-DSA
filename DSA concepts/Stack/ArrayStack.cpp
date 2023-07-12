#include<iostream>
using namespace std;

class stack{
    int *arr;
    int nextIndex;
    int capacity;
    public:
        stack(){
            arr = new int[4];
            capacity = 4;
            nextIndex = 0;
        }
        stack(int cap){
            capacity = cap;
            arr = new int[capacity];
            nextIndex = 0;
        }

        int size(){
            return nextIndex;
        }
        bool isEmpty(){
            /*if(nextIndex == 0){
                return true;
            }else {
                return false;
            } */
            return nextIndex == 0;
        }

        void push(int val){
            if(capacity == nextIndex){
                cout<<"Stack overflow"<<endl;
                return;
            }
            arr[nextIndex] = val;
            nextIndex++;
        }

        void pop(){
            if(isEmpty()){
                cout<<"stack underflow"<<endl;
                return;
            }
            nextIndex--;
        }

        int top(){
            if(nextIndex == 0){
                cout<<"stack empty no element at the top"<<endl;
                return -1;
            }
            return arr[nextIndex-1];
        }
        
};

int main(){
    stack s(4);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.push(50);      /// stack overflow

    cout<<"stack size "<<s.size()<<endl;

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    cout<<"stack size "<<s.size()<<endl;

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    cout<<s.isEmpty()<<endl;

    stack s2(10);
    for(int i=1;i<=10;i++){
        s2.push(i);
    }

    while(!s2.isEmpty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }
    
    cout<<s2.size()<<endl;



}