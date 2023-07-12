#include<iostream>
using namespace std;
template<typename T>
class stack{
    T *arr;
    int nextIndex;
    int capacity;
    public:
        stack(){
            capacity = 4;
            arr = new T[capacity];
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

        void push(T val){
            if(capacity == nextIndex){
                T *NewArr = new T[2*capacity];
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

        T top(){
            if(nextIndex == 0){
                cout<<"stack empty no element at the top"<<endl;
                return -1;
            }
            return arr[nextIndex-1];
        }
        
};

int main(){
    stack<char> s;

    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);  
    
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