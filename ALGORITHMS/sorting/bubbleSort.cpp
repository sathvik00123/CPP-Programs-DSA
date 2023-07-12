#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=1;i<n;i++){
        int flag = 0;
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){        //// array is already sorted
            break;            ////  this is the optimised solution os bubble sort...
        }
    }
    
}

int main(){
    int arr[5] = {4,1,5,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}