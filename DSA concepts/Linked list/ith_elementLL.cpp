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
int length(node *head){
    node *temp = head;
    int count = 0;
    while (temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}
void printithelement(node *head,int i){          /// time complexity = O(i)  (or)  O(n)
    int count = 1;
    if(i<0){
        cout<<"-1"<<endl;
    }
    // no need to get the length of linked list...
    while(count <= i && head != NULL){
        head = head -> next;
        count++;
    }
    if(head != NULL){
        cout<<head->data<<endl;
    }
    else cout<<"-1";
}

int main(){
    node *head = takeinput1();
    print(head);
    length(head);
    printithelement(head,3);
    
    node *head2 = takeinput2();
    print(head2);
    length(head2);
    printithelement(head2,2);
    return 0;
}