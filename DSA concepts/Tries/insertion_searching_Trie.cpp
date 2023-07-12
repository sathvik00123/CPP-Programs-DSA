#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    bool isTerminal;
    node* child[26];
    node(){
        isTerminal = false;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

void add(string word,node* trie){
    int n = word.size();
    for(int i=0;i<n;i++){
        if(trie->child[word[i] - 'A'] == NULL){
            node* stringnode = new node();
            trie->child[word[i] - 'A'] = stringnode;
        }
        trie = trie->child[word[i] - 'A'];
    }
    trie->isTerminal = true;
}

bool search(string word,node* trie){
    int n = word.size();
    for(int i=0;i<n;i++){
        if(trie->child[word[i] - 'A'] == NULL) return false;
        trie = trie->child[word[i] - 'A'];
    }
    return trie->isTerminal;
}

int main(){                                     /// time == O(n)  :: where n is size of string...
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DOT");
    dict.push_back("DO");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");
    // cout<<'E'-'A';

    node* root = new node();

    for(int i=0;i<dict.size();i++){
        add(dict[i],root);
    }

    cout<<search("ARE",root)<<endl;
    cout<<search("NEWS",root)<<endl;
    cout<<search("NEWSA",root)<<endl;
    cout<<search("NOT",root)<<endl;
    cout<<search("MEOW",root)<<endl;
    cout<<search("DO",root)<<endl;
    cout<<search("U",root)<<endl;
    return 0;
}