#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
class btnode{
    public:
    T data;
    btnode *left;
    btnode *right;

    btnode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~btnode(){
        delete left;
        delete right;
    }
};

void postOrderTraversalStack(btnode<int>* root){
    stack<btnode<int>*> s;
    btnode<int>* temp = root;
    if(temp == NULL){
        return;
    }

    // while(!s.empty() || temp != NULL){
        while(temp != NULL){
            s.push(temp);
            if(temp->right != NULL){
                s.push(temp->right);
            }
            temp = temp -> left;
        }
        while(!s.empty()){
            temp = s.top();
            if(temp == root){
                temp = root;
                break;
            }
            cout<<temp->data<<" ";
            s.pop();
        }
    }
// }

btnode<int> *takeinputlevelwise(){
    int rootdata;
    cout<<"Enter the data : "<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    
    btnode<int> *root = new btnode<int>(rootdata);
    queue<btnode<int>*> q;
    q.push(root);

    while(!q.empty()){
        btnode<int>* f = q.front();
        q.pop();
        int leftchilddata,rightchilddata;
        cout<<"Enter the left child of "<<f->data<<endl;
        cin>>leftchilddata;
        if(leftchilddata != -1){
            btnode<int> *child = new btnode<int>(leftchilddata);
            q.push(child);
            f->left = child;
        }
        cout<<"Enter the right child of "<<f->data<<endl;
        cin>>rightchilddata;
        if(rightchilddata != -1){
            btnode<int> *child = new btnode<int>(rightchilddata);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}


int main(){
    btnode<int> *root = takeinputlevelwise();      /// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    postOrderTraversalStack(root);
}