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

int height(treenode<int>* root){
    if(root == NULL){
        return 0;
    }
    int mx = 0;
    for(int i=0;i<root->children.size();i++){
        // int childheight = height(root->children[i]);
        // if(childheight > mx){
        //     mx = childheight;
        // }
        mx = max(mx,height(root->children[i]));
    }
    return mx+1;
}
    
int main(){
    treenode<int> *root = takeinputlevelwise();  // 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0 
    printtreelevelwise(root);
    cout<<"Height "<<height(root)<<endl;
    return 0;
}