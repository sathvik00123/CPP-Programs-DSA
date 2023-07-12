// time == O(n*d)
//auxilary space == O(1)


#include<bits/stdc++.h>
using namespace std;

int rotate(int n,int arr[],int d){
    for(int i=0; i<d; i++){
        int temp = arr[0];
        for(int j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1] = temp;
    }
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]";
    return *arr;
}
int main(){
    int arr[6] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]),d=2;
    rotate(n,arr,d);
    return 0;

}