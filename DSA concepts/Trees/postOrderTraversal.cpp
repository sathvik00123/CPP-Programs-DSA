#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> children;

    treenode(int firstData){
        data = firstData;
    }
};

treenode<int> *takeinput(){
    int rootdata,n,childdata;
    cout<<"enter the root data "<<endl;
    cin>>rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    treenode<int> *temp = root;
    cout<<"no of children of "<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return temp;
}

void PostOrderTraversal(treenode<int> *root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        PostOrderTraversal(root->children[i]);
    }
    cout<<root->data<<" ";
}


int main(){
    treenode<int> *root = takeinput();   //1 3 2 2 5 0 6 0 3 1 7 0 4 1 8 0
    cout<<"PostOrder traversal : ";
    PostOrderTraversal(root);
    return 0;
}