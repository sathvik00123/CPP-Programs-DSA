#include<iostream>
using namespace std;
int ternarySearch(int arr[],int l,int r,int x){
    int mid1,mid2;
    if(r>=l){
        mid1 =l + (r-l)/3;
        mid2 = mid1 + (r-l)/3;
        if(arr[mid1]==x)
            return mid1;
        if(arr[mid2]==x)
            return mid2;
        if(arr[mid1]>x)
            return ternarySearch(arr,l,mid1-1,x);
        if(arr[mid2]<x)
            return ternarySearch(arr,mid2+1,r,x);
    }
    ternarySearch(arr,mid1+1,mid2-1,x);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n=7,x=7,l,r;
    cout<<"index : "<<ternarySearch(arr,l=0,r=n-1,x);
    return 0;
}