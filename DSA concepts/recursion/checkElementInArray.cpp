#include<bits/stdc++.h>
using namespace std;

bool checkElementInArray(int arr[],int n,int key){
    if(n == 0){
        return false;
    }
    bool remArr = checkElementInArray(arr+1,n-1,key);
    if(remArr){
        return true;
    }
    if(arr[0] == key){
        return true;
    }
    else{
        return false;
    }
}

bool checkElementInArray1(int arr[],int n,int key){
    if(n == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    return checkElementInArray1(arr+1,n-1,key);
}

bool checkElementInArray2(int arr[],int n,int key){
    if(n == 0){
        return false;
    }

    if(arr[n-1] == key){
        return true;
    }
    return checkElementInArray2(arr,n-1,key);
}

bool checkElementInArray3(int arr[],int n,int i,int key){
    if(i == n){
        return false;
    }
    if(arr[i] == key){
        return true;
    }
    return checkElementInArray3(arr,n,i+1,key);
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 1;

    if(checkElementInArray(arr,n,key)){
        cout<<"element is present in array..."<<endl; 
    }
    else{
        cout<<"element is not present in array..."<<endl;
    }

    if(checkElementInArray1(arr,n,key)){
        cout<<"element is present in array..."<<endl; 
    }
    else{
        cout<<"element is not present in array..."<<endl;
    }

    if(checkElementInArray2(arr,n,key)){
        cout<<"element is present in array..."<<endl; 
    }
    else{
        cout<<"element is not present in array..."<<endl;
    }

    if(checkElementInArray3(arr,n,0,key)){
        cout<<"element is present in array..."<<endl; 
    }
    else{
        cout<<"element is not present in array..."<<endl;
    }
    return 0;
}