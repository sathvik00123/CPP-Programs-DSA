#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node *next;
    Node(T data){
        this->data = data;
        next = NULL;;
    }

};

template<typename T>
class stack{
    Node<T> *head;
    int size;
    public:
        stack(){
            head = NULL;
            size = 0;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return head == NULL;
        }

        void push(T ele){
            Node<T> *n = new Node<T>(ele);
            if(head == NULL){
                head = n;
            }else {
                n->next = head;
                head = n;
            }
            size++;
        }
        
        void pop(){
            if(head == NULL){
                cout<<"NO elements found"<<endl;
                return;
            }
            Node<T> *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
        T top(){
            if(head == NULL){
                cout<<"NO elements found"<<endl;
                return 0;
            }
            return head->data;
        }

};

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"size of stack "<<s.getSize()<<endl;

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    
    cout<<"size of stack "<<s.getSize()<<endl;
    cout<<s.top()<<endl;

    s.pop();
    s.pop();
    
    cout<<s.top()<<endl;
    cout<<s.isEmpty()<<endl;

}