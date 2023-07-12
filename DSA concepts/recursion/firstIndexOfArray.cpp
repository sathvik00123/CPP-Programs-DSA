#include<bits/stdc++.h>
using namespace std;

int firstIndexOfArray(int arr[],int n,int key,int i){
    if(i==n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstIndexOfArray(arr,n,key,i+1);
}
int main(){
    int arr[10] = {1,2,3,2,5,5,2,3,1,1};
    int key = 2;
    int n = 10;
    cout<<firstIndexOfArray(arr,n,key,0);
    return 0;
}