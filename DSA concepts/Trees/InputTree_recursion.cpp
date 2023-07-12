#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> children;

    treenode(T data){
        this->data = data;
    }
};

treenode<int>* takeinput(){
    int rootdata;
    cout<<"Enter the root data "<<endl;
    cin>>rootdata;
    treenode<int>* root = new treenode<int>(rootdata);
    int n;
    cout<<"number of children of "<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
    }

void print(treenode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}
int main(){
    treenode<int>* root = takeinput();  //1 3 2 2 5 0 6 0 3 1 7 0 4 1 8 0
    print(root);
    return 0;
}