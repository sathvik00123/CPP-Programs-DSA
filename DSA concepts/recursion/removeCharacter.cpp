#include<iostream>
using namespace std;

void removeChar(char arr[],int key){
    if(arr[0] == '\0'){
        return;
    }
    if(arr[0] == 'a'){
        for(int i=0;arr[i] != '\0';i++){
            arr[i] = arr[i+1];
        }
        removeChar(arr,key);
    }
    else{
        removeChar(arr+1,key);
    }
}

int main(){
    char arr[100];
    cin>>arr;
    char key = 'a';
    removeChar(arr,key);
    cout<<arr;
    return 0;
}