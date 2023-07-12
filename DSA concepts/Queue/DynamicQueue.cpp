#include<iostream>
using namespace std;

template<typename T>
class Queue{
    T *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    Queue(){
        capacity = 5;
        arr = new T[capacity];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void push(T val){
        if(nextIndex == firstIndex){
            int *newArr = new int[capacity*2];
            int j=0;
            for(int i=firstIndex;i<capacity;i++){
                newArr[j] = arr[i];
                j++;
            }
            for(int i=0;i<=firstIndex;i++){
                newArr[j] = arr[i];
                j++;
            }
            firstIndex = 0;
            nextIndex = capacity;
            capacity = capacity*2;
            delete []arr;
            arr = newArr;
        }
        arr[nextIndex] = val;
        nextIndex = (nextIndex+1)%capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }
    
    T front(){
        if(isEmpty()){
            cout<<"Queue empty"<<endl;
            return 0;
        }
        return arr[firstIndex];
    }
    
    T rear(){
        if(isEmpty()){
            cout<<"Queue empty"<<endl;
            return 0;
        }
        if(nextIndex == 0){
            return arr[capacity-1];
        }
        return arr[nextIndex-1];
    }
    

    void pop(){
        if(isEmpty()){
            cout<<"Queue empty"<<endl;
            return;
        }
        firstIndex = (firstIndex + 1)%capacity;
        size--;
    }
};

int main(){
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"size "<<q.getSize()<<endl;
    cout<<"front "<<q.front()<<endl;
    q.push(40);
    q.push(50);
    cout<<"isFull "<<q.isFull()<<endl;
    cout<<"rear "<<q.rear()<<endl;
    q.push(60);
    q.push(70);

    cout<<"size "<<q.getSize()<<endl;
    q.pop();
    q.push(60);
    cout<<"rear "<<q.rear()<<endl;
    q.push(70);

    cout<<"isEmpty "<<q.isEmpty()<<endl;
    cout<<"size "<<q.getSize()<<endl;
    q.pop();
    cout<<"front "<<q.front()<<endl;
    q.pop();
    cout<<"rear "<<q.rear()<<endl;
    cout<<"front "<<q.front()<<endl;
    cout<<"isEmpty "<<q.isEmpty()<<endl;
    return 0;
}