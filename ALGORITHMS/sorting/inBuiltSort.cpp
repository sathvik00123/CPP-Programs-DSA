#include<bits/stdc++.h>  //// master header file which includes all header files...
using namespace std;



int main(){
    int arr[6] = {6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}