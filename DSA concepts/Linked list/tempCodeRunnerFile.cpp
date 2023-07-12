#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int data){                               //this program is working on online compiler...
        this->data = data;
        this->next = next;
    }
};
void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}
node *takeinput1(){
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1){
        node *n = new node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail -> next = n;
            tail = n;                 // adding at end...
        }
        cin>>data;
    }
    return head;
}
node *takeinput2(){
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1){
        node *n = new node(data);
        if(tail == NULL){
            head = n;
            tail = n;
        }
        else{
            n -> next = head;
            head = n;                 // reversing a LL...
        }
        cin>>data;
    }
    return tail;
}

int main(){
    node *head = takeinput1();
    print(head);
    node *head = takeinput2();
    print(head);
}