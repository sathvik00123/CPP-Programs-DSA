#include<iostream>
#include<vector>
#include<queue>
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

treenode<int> *takeinputlevelwise(){
        int rootdata;
        cout<<"Enter the root node data :"<<endl;
        cin>>rootdata;
        treenode<int>* root = new treenode<int>(rootdata);
        queue <treenode<int>*> q;
        q.push(root);
        while(! q.empty()){
            treenode<int>* f = q.front();
            q.pop();
            int n;
            cout<<"enter number of children of "<<f->data<<endl;
            cin>>n;
            for(int i=1;i<=n;i++){
                int childdata;
                cout<<"enter the "<<i<<" th child of node "<<f->data<<endl;
                cin>>childdata;

                treenode<int>* child = new treenode<int>(childdata);
                q.push(child);
                f->children.push_back(child);
            }
        }
            return root;
    }

void printtreelevelwise(treenode<int>* root){
    queue <treenode<int>*> q;
    q.push(root);
    while(! q.empty()){
        treenode<int>* f = q.front();
        q.pop();

        cout<<f->data<<":";
    for(int i=0;i<f->children.size();i++){
        cout<<f->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<f->children.size();i++){
        q.push(f->children[i]);
    }
}
}

int countLeafNodes(treenode<int>* root){
    if(root == NULL){
        return 1;
    }
    if(root->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for(int i=0;i<root->children.size();i++){
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}

 // OR

 int countLeafNodesOtherMethod(treenode<int>* root,int &ans){
    if(root == NULL){
        return 1;
    }
    if(root->children.size() == 0){
        ans++;
        return 0;
    }
    for(int i=0;i<root->children.size();i++){
        countLeafNodesOtherMethod(root->children[i],ans);
    }
    return ans;
 }
    
int main(){
    treenode<int> *root = takeinputlevelwise();    // 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0 
    printtreelevelwise(root);
    cout<<"leaf nodes of a tree "<<countLeafNodes(root)<<endl;
    int totalLeafNodes = 0;
    countLeafNodesOtherMethod(root,totalLeafNodes);
    cout<<"leaf nodes of a tree "<<totalLeafNodes<<endl;
    return 0;
}