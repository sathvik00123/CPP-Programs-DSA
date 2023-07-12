#include<iostream>
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
        return ;
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
int main(){
    btnode<int> *root = new btnode<int>(1);
    btnode<int> *n1 = new btnode<int>(2);
    btnode<int> *n2 = new btnode<int>(3);

    root->left = n1;
    root->right =n2;

    printBT(root);
    delete root;
}