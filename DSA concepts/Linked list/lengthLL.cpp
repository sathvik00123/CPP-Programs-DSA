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
            tail = n;                 // inserting at end...
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
            head = n;                 //  inserting at beginning..
        }
        cin>>data;
    }
    return head;
}
void length(node *head){
    node *temp = head;
    int count = 0;
    while (temp != NULL){
        temp = temp -> next;
        count++;
    }
    cout<<"length of LL : "<<count<<endl;
}

int main(){
    node *head = takeinput1();
    print(head);
    length(head);
    
    node *head2 = takeinput2();
    print(head2);
    length(head2);
    return 0;
}