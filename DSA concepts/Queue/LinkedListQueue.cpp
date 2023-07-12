#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    int data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;
    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool isEmpty(){
        return size==0;
    }

    int getSize(){
        return size;
    }

    void push(T ele){
        Node<T> *n = new Node<T>(ele);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        size++;
    }
    
    T front(){
        if(isEmpty()){
            cout<<"queue empty ";
            return 0;
        }
        return head->data;
    }
    T rear(){
        if(isEmpty()){
            cout<<"queue empty ";
            return 0;
        }
        return tail->data;
    }

    void pop(){
        if(isEmpty()){
            cout<<"queue empty ";
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
};

int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.getSize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.rear()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getSize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.rear()<<endl;
    return 0;
}