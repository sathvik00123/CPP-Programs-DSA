// time == O(n)
//auxilary space == O(1)


#include<bits/stdc++.h>
using namespace std;
int rev(int dum[],int s,int e){
    while(s<e){
        swap(dum[s],dum[e]);
        s++;
        e--;
    }
}
int leftRot(int arr[], int n, int d){
    int A[n] = {},B[n] = {};
    for(int i=0;i<d;i++){
        A[i] = arr[i];
    }
    for(int i=d;i<n;i++){
        B[i] = arr[i];
    }
    rev(A,0,d-1);
    rev(B,d,n-1);
    for(int i=0;i<d;i++){
        arr[i] = A[i];
    }
    for(int i=d;i<n;i++){
        arr[i] = B[i];
    }
    rev(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[9] = {7,8,9,1,2,3,4,5,6},d=3;
    int n = sizeof(arr)/sizeof(arr[0]);
    leftRot(arr,n,d);
}