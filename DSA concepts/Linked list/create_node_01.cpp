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
int main(){
    /// statically object creation...
    node n1(1);
    node n2(2);
    
    n1.next = &n2;
    cout<<n1.data<<" -> "<<n2.data<<endl;

    node *head = &n1;
    cout<<head->data<<endl;

    /// dynamically object creation...
    node *n3 = new node(3);
    node *n4 = new node(4);

    n2.next = n3;
    n3->next = n4;
    
    cout<<n1.data<<" -> "<<n2.data<<" -> "<<n3->data<<" -> "<<n4->data<<endl;
    // printLL();
    return 0;
}