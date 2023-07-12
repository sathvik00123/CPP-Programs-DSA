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

int minValue(btnode<int>* root){
    if(root == NULL){
        return INT16_MAX;
    }
    
    return min(root->data,min(minValue(root->left),minValue(root->right)));
}

void minValueOtherMethod(btnode<int>* root,int &ans){
    if(root == NULL){
        return;
    }
    ans = min(root->data,ans);
    minValueOtherMethod(root->left,ans);
    minValueOtherMethod(root->right,ans);
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
    btnode<int> *root = takeinputlevelwise();      /// 1 2 3 4 5 6 -90 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    cout<<"minimun value in the given BT : "<<minValue(root)<<endl;
    int maxVal = INT16_MAX;
    minValueOtherMethod(root,maxVal);
    cout<<"minimum value in the given BT : "<<maxVal;
    // delete root;
}