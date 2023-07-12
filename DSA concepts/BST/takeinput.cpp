#include<iostream>

using namespace std;
template<typename T>
class bstnode{
    public:
    T data;
    bstnode* left;
    bstnode* right;

    bstnode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printBST(bstnode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left){
        cout<<root->left->data<<"L, ";
    }
    if(root->right){
        cout<<root->right->data<<"R ";
    }
    cout<<endl;
    printBST(root->left);
    printBST(root->right);

}

// bstnode<int>* takeInputRecurrsively(){
    
//     return root;
// }
int main(){
    bstnode<int>* root = new bstnode<int>(40);
    bstnode<int>* n1 = new bstnode<int>(30);
    bstnode<int>* n2 = new bstnode<int>(50);
    bstnode<int>* n3 = new bstnode<int>(10);
    bstnode<int>* n4 = new bstnode<int>(35);
    bstnode<int>* n5 = new bstnode<int>(45);
    bstnode<int>* n6 = new bstnode<int>(55);

    root->left = n1;
    root->right = n2;
    root->left->left = n3;
    root->left->right = n4;
    root->right->left = n5;
    root->right->right = n6;
    
    // bstnode<int>* root = takeInputRecurrsively();
    printBST(root);
    return 0;
}