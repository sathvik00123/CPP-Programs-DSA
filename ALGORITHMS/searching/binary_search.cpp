#include<iostream>
using namespace std;
int binSea(int arr[],int l,int r,int srh){
    if(l<=r){
        int mid = (l + r)/2;
        if(arr[mid] == srh)
            return mid;
        if(arr[mid] > srh)
            return binSea(arr,l,mid-1,srh);
        return binSea(arr,mid+1,r,srh);
    }
    return -1;
}
int main()
{
    int arr[6] = {1,2,3,4,5,6},n,l,r,srh = 8;
    n = sizeof(arr)/sizeof(arr[1]);
    cout<<"index found at: "<<binSea(arr,l=0,r=n-1,srh);
    return 0;
}