#include<bits/stdc++.h>
using namespace std;
int binSea(int arr[], int, int, int);
int expoSearch(int arr[],int n,int key){
    if(arr[0]==key){
        return 0;
    }
    int i=1;
    while(i<n && arr[i]<=key){
        i = i*2;
    }
    return binSea(arr,i/2,min(i,n-1),key);
}
int binSea(int arr[],int l,int r,int key){
    if(r>=l){
        int mid = (r-l)+l/2;
        if(arr[mid]==key) 
            return mid;

        if(arr[mid]>key) 
            return binSea(arr,l,mid-1,key);

        return binSea(arr,mid+1,r,key);
    }
    return -1;
}

int main(void){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 3;
    int result = expoSearch(arr, n, key);
   (result == -1)? cout <<"Element is not present in array"
                 : cout <<"Element is present at index " << result;
    return 0;
}