#include<bits/stdc++.h>  //// master header file which includes all header files...
using namespace std;

int  sumarr1(int arr[],int i,int n){
    if(i==n){
        return 0;
    }
    return arr[i]+sumarr1(arr,i+1,n);
}

int sumarr2(int arr[],int n){
    if(n==0){
        return 0;
    }
    return arr[0] + sumarr2(arr+1,n-1);
}

int sumarr3(int arr[],int n){
    if(n==0){
        return 0;
    }

    return arr[n-1] + sumarr3(arr,n-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sumarr1(arr,0,n)<<endl;
    cout<<sumarr2(arr,n)<<endl;
    cout<<sumarr3(arr,n)<<endl;
}