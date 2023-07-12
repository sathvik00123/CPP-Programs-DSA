#include<iostream>
using namespace std;

void printAllPositionIndex(int arr[],int n,int key,int i){
    if(i == n){
        return;
    }
    if(arr[i] == key){
        cout<<i<<endl;
    }
    printAllPositionIndex(arr,n,key,i+1);
}
int main(){
    int arr[7] = {5,5,6,7,5,5,6};
    printAllPositionIndex(arr,7,6,0);
}