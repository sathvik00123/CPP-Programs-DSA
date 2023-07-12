#include<iostream>
using namespace std;

void printPrefixes(int arr[],int n){
    for(int e=0;e<n;e++){
        for(int s=0;s<=e;s++){
            cout<<s<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    printPrefixes(arr,n);
    return 0;
}