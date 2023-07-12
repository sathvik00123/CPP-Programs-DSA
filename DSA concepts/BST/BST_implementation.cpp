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

    ~bstnode(){
        delete left;
        delete right;
    }

};

class pair{
    public:
    bstnode<int>* head;
    bstnode<int>* tail;
};

class BST{
    bstnode<int>* root;

    void printBT(bstnode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    printBT(root->left);
    printBT(root->right);
    }

    bool hasData(bstnode<int> *node,int data){
        if(node == NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }

        if(node->data > data){
            return hasData(node->left,data);
        }
        else{
            return hasData(node->right,data);
        }
    }

    bstnode<int>* insertD(bstnode<int>* node,int data){
        if(node == NULL){
            bstnode<int>* n1 = new bstnode<int>(data);
            return n1;
        }
        if(node->data > data){
            node->left = insertD(node->left,data);
        }
        else{
            node->right = insertD(node->right,data);
        }
        return node;
    }

    bstnode<int>* deleteD(bstnode<int> *node,int data){
        if(node == NULL){
            return NULL;
        }

        if(data > node->data){
            node->right = deleteD(node->right,data);
        }
        else if(data < node->data){
            node->left = deleteD(node->left,data);
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->right == NULL){
                bstnode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if(node->left == NULL){
                bstnode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else{
                bstnode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                deleteD(node->right,rightMin);
            }   
        }
        return node;
    }

    pair connectToLL(bstnode<int>* root){
        if(root == NULL){
            pair ans;
            ans.head = NULL;
            ans.tail = NULL;
            return ans;
        }
        if(root->left == NULL && root->right == NULL){
            pair p;
            p.head = root;
            p.tail = root;
            return p;
        }
        else if(root->left != NULL && root->right == NULL){
            pair leftLL = connectToLL(root->left);
            leftLL.tail->right = root;
            pair ans;
            ans.head = leftLL.head;
            ans.tail = root;
            return ans;
        }
        else if(root->left == NULL && root->right != NULL){
            pair rightLL = connectToLL(root->right);
            root->right = rightLL.head;
            pair ans;
            ans.head = root;
            ans.tail = rightLL.tail;
            return ans;
        }
        else{
            pair leftLL = connectToLL(root->left);
            pair rightLL = connectToLL(root->right);
            leftLL.tail->right = root;
            root->right = rightLL.head;
            pair ans;
            ans.head = leftLL.head;
            ans.tail = rightLL.tail;
            return ans;
        }
    }


    public:
        BST(){
            root = NULL;
        }

        ~BST(){
            delete root;
        }

        void deleteData(int data){
            root = deleteD(root,data);
        }

        void insertData(int data){
            root = insertD(root,data);
        }

        bool hasData(int data){
            return hasData(root,data);
        }

        void print(){
            printBT(root);
        }
        bstnode<int>* convertToLL(){
            pair p = connectToLL(root);
            bstnode<int>* tmp = p.head;
            while(tmp!=NULL){
                tmp->left = NULL;
                tmp = tmp->right;
            }
            return p.head;
        }
};

int main(){
    BST b;
    b.insertData(10);
    b.insertData(42);
    b.insertData(2);
    b.insertData(15);
    b.insertData(5);
    b.insertData(23);
    b.insertData(4);

    b.print();

    bstnode<int>* head = convertToLL();
    bstnode<int>* tmp = head;
    while(tmp!=NULL){
        cout<<tmp->data<<" -> ";
        tmp = tmp->right;
    }

    cout<<endl;
    // int val;
    // cin>>val;
    // cout<<b.hasData(val)<<endl;
    // b.deleteData(10);
    // b.print();
    // cout<<endl;
    // b.deleteData(15);
    // b.print();
    // cout<<endl;
    // b.deleteData(23);
    // b.print();
    // cout<<endl;
    // b.deleteData(2);
    // b.print();
    // b.deleteData(42);
    // b.print();
    return 0;
}