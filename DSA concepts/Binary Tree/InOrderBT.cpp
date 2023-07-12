#include<iostream>
#include<queue>
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

// void printBT(btnode<int> *root){
//     if(root == NULL){
//         return;
//     }
//     cout<<root->data<<": ";
//     if(root->left != NULL){
//         cout<<"L"<<root->left->data<<" ";
//     }
//     if(root->right != NULL){
//         cout<<"R"<<root->right->data<<" ";
//     }
//     cout<<endl;
//     printBT(root->left);
//     printBT(root->right);
// }

void printInOrderTraversalBT(btnode<int> *root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        printInOrderTraversalBT(root->left);
    }
    cout<<root->data<<": "<<endl;
    if(root->right != NULL){
        printInOrderTraversalBT(root->right);
    }    
}

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
    btnode<int> *root = takeinputlevelwise();      /// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    printInOrderTraversalBT(root);
    // delete root;
}