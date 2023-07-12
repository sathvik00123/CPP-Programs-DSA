#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> children;

    // destructor funnction...
    ~treenode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }

    treenode(int firstData){
        data = firstData;
    }
};

treenode<int> *takeinput(){
    int rootdata,n,childdata;
    cout<<"enter the root data "<<endl;
    cin>>rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    cout<<"no of children of "<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int> *child = takeinput();
        root->children.push_back(child);
    }
}



int main(){
    treenode<int> *root = takeinput();   //1 3 2 2 5 0 6 0 3 1 7 0 4 1 8 0
    delete root;
    return 0;
}