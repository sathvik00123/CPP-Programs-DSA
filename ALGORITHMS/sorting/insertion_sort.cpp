#include <iostream>
using namespace std;
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int value = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>value){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = value;
    }
}
int main(){
    int arr[7] = {98,32,76,43,86,42,11};
    int n=7;
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}