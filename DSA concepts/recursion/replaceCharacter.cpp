#include<iostream>

using namespace std;

void replaceChar(char arr[],int replace,int key){
    if(arr[0] == '\0'){
        return;
    }
    if(arr[0] == key){
        arr[0] = replace;
    }
    replaceChar(arr+1,replace,key);
}

int main(){
    char arr[100];
    cin>>arr;
    // int len = length(arr);
    // cout<<len<<endl;
    char replace = 'x';
    char key = 'a';
    replaceChar(arr,replace,key);
    cout<<arr;
    return 0;
}