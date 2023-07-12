#include<iostream>
using namespace std;

int parition1(int arr[],int s,int e){
    int i = s,j = s;
    int pivot = arr[e];

    while(j < e){
        if(pivot > arr[j]){
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[e],arr[i]);
    return i;
}

void quickSort1(int arr[],int s,int e){
    if(s>=e){
        return;
    }

    int p = parition1(arr,s,e);
    quickSort1(arr,s,p-1);
    quickSort1(arr,p+1,e);
}

// int countsmallest(int arr[],int s,int e){
//     int co = 0;
//     for(int i=s;i<e;i++){
//         if(arr[i] < arr[e]){
//             co++;
//         }
//     }
//     return co;
// }
int parition2(int arr[],int s,int e){
    // int count = s + countsmallest(arr,s,e);
    // swap(arr[e],arr[count]);
    int pivot = arr[e];
    int i = s;
    int j = e-1;
    while(i < j){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[e]);
    return i;
}

void quickSort2(int arr[],int s,int e){
    if(s < e){
        int p = parition2(arr,s,e);
        quickSort2(arr,s,p-1);
        quickSort2(arr,p+1,e);
    }
}

int main(){
    int arr[] = {55,-2,77,22,-1,88,66,-2,33,11,44};
    int n = sizeof(arr)/sizeof(arr[0]);
    // quickSort1(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort2(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}