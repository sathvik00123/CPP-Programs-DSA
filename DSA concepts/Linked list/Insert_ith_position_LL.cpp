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
    // node *temp = head;
    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head -> next;
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

node *insert_ith_node_method1(node *head,int i,int data){            //  method  1
    if(i<0){
        return head;
    }
    
    if(i==0){
        node *n = new node(data);
        n->next = head;
        head = n;
        return head;
    }

    node *temphead = head;
    if(i>0){
        int count=1;
        while(count <= i-1 && head != NULL){
            head = head -> next;
            count++;
        }
        
        node *n = new node(data);
        if(head != NULL){
            n->next = head->next;
            head->next = n;
            return temphead;
        }
        return temphead;
    }
}

node *delete_node(node* head,int k){
    if(k<0){
        return head;
    }

    if(k==0 && head != NULL){         /// memory leakage is occured...
        return head->next;
    }

    if(k>0){
        node *temp = head;
        int count=1;
        while(count <= k-1 && head != NULL){  
            head = head -> next;
            count++;
        }
        
        if(head != NULL && head-> next != NULL){          /// memory leakage is occured...
            head-> next = head -> next -> next;
            return temp;
        }
        return temp;
    }


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

node *insert_ith_node_method2(node *head2,int j,int data2){     ///   method 2
    if(j<0){
        return head2;
    }

    if(j==0){
        node *n = new node(data2);
        n->next = head2;
        head2 = n;
        return head2;
    }

    node *temphead2 = head2;
    if(j>0){
        int count = 1;
        while(count <= j-1 && head2 != NULL){
            head2 = head2 -> next;
            count++;
        }

        node *tempaddr_ith_node = head2->next; 
        if(head2 != NULL){
            node *n = new node(data2);
            head2->next = n;
            n -> next = tempaddr_ith_node;
            return temphead2;
        }
        return temphead2;
    }
}

node *delete_node2(node* head2,int h){
    if(h<0){
        return head2;
    }

    if(h==0){
        node *newhead = head2->next;       /// memory leakage is fixed...
        head2->next = NULL;
        delete head2;
        return newhead;
    }

    if(h>0){
        node *curr = head2;
        int count=1;
        while(count <= h-1 && head2 != NULL){  
            head2 = head2 -> next;
            count++;
        }
        
        if(head2 != NULL && head2 -> next != NULL){         /// memory leakage is fixed...
            node *temp = head2 -> next;
            head2-> next = head2 -> next -> next;
            temp -> next = NULL;
            delete temp;
            return curr;
        }
        return curr;
    }
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
    int i,data;
    cin>>i>>data;
    head = insert_ith_node_method1(head,i,data);
    int k;
    cin>>k;
    head = delete_node(head,k);
    print(head);
    cout<<length(head);
    printithelement(head,3);
    
    // node *head2 = takeinput2();
    // print(head2);
    // int j,data2;
    // cin>>j>>data2;
    // head2 = insert_ith_node_method2(head2,j,data2);
    // int h;
    // cin>>h;
    // head2 = delete_node2(head2,h);
    // print(head2);
    // cout<<length(head2);
    // printithelement(head2,2);
    return 0;
}