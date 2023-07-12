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

void print(treenode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ,";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }

}
int main(){
    treenode<int>* root = new treenode<int>(1);
    treenode<int>*  n1 = new treenode<int>(2);
    treenode<int>* n2 = new treenode<int>(3);
    treenode<int>* f1 = new treenode<int>(4);
    treenode<int>* f2 = new treenode<int>(5);
    treenode<int>* f3 = new treenode<int>(6);
    treenode<int>* f4 = new treenode<int>(7);


    root->children.push_back(n1);                    //                             1
    root->children.push_back(n2);                    //                           /    \ 
    n1->children.push_back(f1);                      //                          2       3
    n1->children.push_back(f2);                      //                       /  |  \   /
    n1->children.push_back(f3);                      //                      4   5   6  7
    n2->children.push_back(f4);
    print(root);     // we are doing depth-first-search(dfs).
    return 0;
}