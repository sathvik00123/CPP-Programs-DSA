#include<iostream>
#include<stack>
using namespace std;

bool validParanthesis(string a){
    stack<char> s;

    for(int i=0;i<a.length();i++){
        if(a[i] == '(' || a[i] == '{' || a[i] == '['){
            s.push(a[i]);
        }
        else{
            if(s.empty()) return false;    ///  this is important to be noted...
            else if(a[i] == ')'){
                if(s.top() == '(') s.pop();
                else return false;
            }
            else if(a[i] == '}'){
                if(s.top() == '{') s.pop();
                else return false;
            }
            else if(a[i] == ']'){
                if(s.top() == '[') s.pop();
                else return false;
        }
    }
    }
    
    if(s.empty()) return true;
    return false;
}

int main(){
    string a;
    cin>>a;
    cout<<validParanthesis(a);
    return 0;
}