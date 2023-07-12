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

int rangesumBST(bstnode<int>* root,int leftRange,int rightRange){       // Range  ==  [3,7]
    if(root == NULL) return 0;

    int sum = 0;
    if(root->data >= leftRange && root->data <= rightRange){
        sum += root->data;
    } 

    if(root->data < leftRange){
        sum += rangesumBST(root->right,leftRange,rightRange);
    }
    else if(root->data > rightRange){
        sum += rangesumBST(root->left,leftRange,rightRange);
    }
    else{
        sum += rangesumBST(root->left,leftRange,rightRange) + rangesumBST(root->right,leftRange,rightRange);
    }
    return sum;
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
    cout<<rangesumBST(root,3,7);
}