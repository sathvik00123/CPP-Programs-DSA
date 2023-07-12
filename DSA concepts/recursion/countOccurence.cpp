#include<iostream>
using namespace std;

void countFun(int arr[],int n,int key,int count){
    if(n == 0){
        cout<<count<<endl;
        return;
    }
    if(arr[0] == key){
        count++;
    }
    countFun(arr+1,n-1,key,count);
}

void countFun1(int arr[],int n,int key,int i,int &ans){
    if(i==n){
        return;
    }
    if(arr[i] == key){
        ans++;
    }
    countFun1(arr,n,key,i+1,ans);
}

int countFun2(int arr[],int n,int key,int i){
    if(i==n){
        return 0;
    }

    if(arr[i] == key){
        return 1 + countFun2(arr,n,key,i+1);
    }
    else{
        return 0 + countFun2(arr,n,key,i+1);
    }
}

int main(){
    int arr[7] = {5,5,6,7,5,5,6};
    int key = 5;
    countFun(arr,7,key,0);

    int ans = 0;
    countFun1(arr,7,key,0,ans);
    cout<<ans<<endl;

    cout<<countFun2(arr,7,key,0)<<endl;\
    return 0;
}