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

void printBT(btnode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printBT(root->left);
    printBT(root->right);
}

btnode<int> *takeinput(){
    int rootdata;
    cout<<"Enter the data : "<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    
    btnode<int> *root = new btnode<int>(rootdata);
    btnode<int> *leftchild = takeinput();
    btnode<int> *rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;

    return root;
}
int main(){
    btnode<int> *root = takeinput();      /// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    printBT(root);
    // delete root;
}