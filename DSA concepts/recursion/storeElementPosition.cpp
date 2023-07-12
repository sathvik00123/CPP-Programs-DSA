#include<iostream>
#include<vector>
using namespace std;

void storeElementPositionUsingVector(int arr[],int n,int key,int i,vector<int> &ans){
    if(i == n){
        return;
    }
    if(arr[i] == key){
        ans.push_back(i);
    }
    storeElementPositionUsingVector(arr,7,key,i+1,ans);
}

int storeElementPositionUsingArray(int arr[],int n,int key,int i,int out[],int j){
    if(i == n){
        return 0;
    }

    if(arr[i] == key){
        out[j] = i;
        return 1 + storeElementPositionUsingArray(arr,n,key,i+1,out,j+1);
    }
    return 0 + storeElementPositionUsingArray(arr,n,key,i+1,out,j);
}

int main(){
    int arr[] = {5,5,6,7,5,5,6};
    int key=7;

    vector<int> v;
    storeElementPositionUsingVector(arr,7,key,0,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    int out[8];
    int count = storeElementPositionUsingArray(arr,7,key,0,out,0);
    for(int i=0;i<count;i++){
        cout<<out[i]<<" ";
    }
}