#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};
void print(node *head){
        node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
        temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<endl;



        while(head != NULL){
            cout<<head->data<<" -> ";
            head = head->next;
        }
        cout<<endl;
        // here head->NULL so the below while will not run
        //so its better to use a temp variable...
        while(head != NULL){
            cout<<head->data<<" -> ";
            head = head->next;
        }
        cout<<endl;
    }
int main(){
    /// statically object creation...
    node n1(1);
    node *head = &n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    print(head);
    return 0;
}