#include<bits/stdc++.h>
using namespace std;

int lastIndexOfArray(int arr[],int n,int key,int i){
    if(i<0){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return lastIndexOfArray(arr,n,key,i-1);
}

int lastIndexOfArray1(int arr[],int n,int key){
    if(n==0){
        return -1;
    }
    if(arr[n-1] == key){
        return n-1;
    }
    return lastIndexOfArray1(arr,n-1,key);
}

int lastIndexOfArray2(int arr[],int n,int key,int i){
    if(i == n){
        return -1;
    }

    int idxInRem = lastIndexOfArray2(arr,n,key,i+1);
    if(idxInRem == -1){
        if(arr[i] == key){
            return i;
        }
        else{
            return -1;
        }
    }
    else{
        return idxInRem;
    }
}
int main(){
    int arr[10] = {1,2,3,2,5,5,2,3,1,1};
    int key = 1;
    int n = 10;
    cout<<lastIndexOfArray(arr,n,key,n-1)<<endl;
    cout<<lastIndexOfArray1(arr,n,key)<<endl;
    cout<<lastIndexOfArray2(arr,n,key,0)<<endl;
    return 0;
}