#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class bstnode{
    public:
    T data;
    bstnode *left;
    bstnode *right;

    bstnode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
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


///  recurrsively
bstnode<int>* searchNode1(bstnode<int>* root,int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
        // cout<<"Element is found "<<endl;
    }
    if(val < root->data){
        return searchNode1(root->left,val);
    }
    if(val > root->data){
        return searchNode1(root->right,val);
    }
    return NULL;
}

///  Iteratively
bstnode<int>* searchNode2(bstnode<int>* root,int val){
    while(root != NULL){
    if(root->data == val) return root;
    else if(val < root->data){
        root = root->left;
    }
    else{
        root = root->right;
    }
    }
    return NULL;
}


bstnode<int> *takeinputlevelwise(){
    int rootdata;
    cout<<"Enter the data : "<<endl;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    
    bstnode<int> *root = new bstnode<int>(rootdata);
    queue<bstnode<int>*> q;
    q.push(root);

    while(!q.empty()){
        bstnode<int>* f = q.front();
        q.pop();
        int leftchilddata,rightchilddata;
        cout<<"Enter the left child of "<<f->data<<endl;
        cin>>leftchilddata;
        if(leftchilddata != -1){
            bstnode<int> *child = new bstnode<int>(leftchilddata);
            q.push(child);
            f->left = child;
        }
        cout<<"Enter the right child of "<<f->data<<endl;
        cin>>rightchilddata;
        if(rightchilddata != -1){
            bstnode<int> *child = new bstnode<int>(rightchilddata);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}

int main(){
    bstnode<int> *root = takeinputlevelwise();      /// 4 3 6 1 2 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    searchNode1(root,2);
    searchNode2(root,2);
}