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

bool nodePath(btnode<int>* root,int p,vector<int> &ans){
    if(root == NULL){
        return false;
    }
    ans.push_back(root->data);
    if(root->data == p){
        return true;
    }

    bool left =  nodePath(root->left,p,ans);
    bool right = nodePath(root->right,p,ans);
    
    if(left || right){
        return true;
    }
    ans.pop_back();
    return false;
}

int main(){
    btnode<int> *root = takeinputlevelwise();      /// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    vector<int> v;
    if(nodePath(root,7,v)){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    else{
        cout<<"element 7 is not found in the given binary tree"<<endl;
    }
}