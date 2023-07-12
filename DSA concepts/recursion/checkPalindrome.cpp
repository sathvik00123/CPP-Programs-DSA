#include<iostream>
using namespace std;

bool checkpalin(int arr[],int s,int e){
    if(s>e){
        return true;
    }
    if(arr[s] == arr[e]){
        return checkpalin(arr,s+1,e-1);
    }else{
        return false;
    }
}

int main(){
    int arr[] = {1,2,3,4,3,2,1};
    if(checkpalin(arr,0,6)){
        cout<<"is a palindrome"<<endl;
    }
    else{
        cout<<"is not a palindrome"<<endl;
    }
    return 0;
}