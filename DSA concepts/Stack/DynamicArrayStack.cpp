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
                int *NewArr = new int[2*capacity];
                for(int i=0;i<2*capacity;i++){
                    NewArr[i] = arr[i];
                }
                delete arr;
                arr = NewArr;
                capacity = 2*capacity;
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
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);  
    s.push(60); 
    s.push(70);  
    
    cout<<"stack size "<<s.size()<<endl;

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    cout<<"stack size "<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}