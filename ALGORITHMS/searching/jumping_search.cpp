#include<iostream>
#include<math.h>
using namespace std;
int linear(int arr[],int n,int m,int key){
    for(int i=m;i>=0;i--){
        if(arr[i] == key){
            return i;
        }
        return i;
    }
}
int jumpSea(int arr[],int n,int m,int key){
    for(int i=0;i<n;i++){
        m = i+m-1;
        if(arr[i] == key) {
        return (i+m-1);
        }
        if(arr[m] > key){
            return linear(arr, n, m, key);
        }
    }
}
int main(){
    int arr[9] = {11,22,33,44,55,66,77,88,99},n;
    n = sizeof(arr)/sizeof(arr[0]);
    int m = sqrt(n),key = 9,result;
    result = jumpSea(arr,n,m,key);
    if(result == -1) cout<<"element is not found"<<endl;
    else cout<<"element "<<key<<" is found at idx "<<result<<endl;
    return 0;
}