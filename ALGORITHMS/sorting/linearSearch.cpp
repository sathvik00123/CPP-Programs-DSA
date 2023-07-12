#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        } 
    }
    return false;
}

int main(){
    int arr[] = {23,3,10,5,12,45};
    int key = 128;
    int n = sizeof(arr)/sizeof(arr[0]);
    if(linearSearch(arr,key,n)){
        cout<<"key found"<<endl;
    }
    else{
        cout<<"key not found"<<endl;
    }
}