//time complexity ==  O(n)

// #include<bits/stdc++.h>
// using namespace std;

// int linearSearch(int arr[],int key,int n){
//     for(int i=0;i<n;i++){
//         if(arr[i] == key) 
//             return i;
//     }
//     return -1;
// }
// int main(){
//     int arr[5]={1,2,3,4,5};
//     int key = 5,idx,n;
//     n = sizeof(arr)/sizeof(arr[0]);
//     idx = linearSearch(arr,key,n);
//     if(idx == -1){
//         cout<<"The element is not found in the arr"<<endl;
//     }
//     else cout<<"The element is found at index "<<idx<<" and the element is "<<key<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int LS(int arr[],int n, int key){
    if(n==0) return -1;
    if(arr[n] == key){
        return n;
    }
    else{
        int ans = LS(arr,n-1,key);
        return ans;
    }
}
int main(){
    int arr[5] = {1,2,3,4,5},n,key=3,idx;
    n=sizeof(arr)/sizeof(arr[0]);
    idx = LS(arr,n,key);
    if(idx == -1){
        cout<<"The element is not found in the arr"<<endl;
    }
    else cout<<"The element is found at index "<<idx<<" and the element is "<<key<<endl;
    return 0;
}