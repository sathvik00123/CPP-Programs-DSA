#include<bits/stdc++.h>  //// master header file which includes all header files...
using namespace std;

bool isSorted1(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    return isSorted1(arr+1,n-1);
}

bool isSorted2(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[n-2] > arr[n-1]){
        return false;
    }
    return isSorted2(arr,n-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(isSorted1(arr,n)){
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }

    if(isSorted2(arr,n)){
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
}