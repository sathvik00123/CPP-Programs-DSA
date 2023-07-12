#include <iostream>
using namespace std;

void mergeArrays(int x[],int y[],int arr[],int s,int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    while(i<=mid && j<=e){
        if(x[i] < y[j]){
            arr[k] = x[i];
            i++;
            k++;
        }else{
            arr[k] = y[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        arr[k] = x[i];
        i++;
        k++;
    }
    while(j<=e){
        arr[k] = y[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int s,int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    int x[100],y[100];
    for(int i=0;i<=mid;i++){
        x[i] = arr[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = arr[i];
    }
    mergesort(x,s,mid);
    mergesort(y,mid+1,e);
    mergeArrays(x,y,arr,s,e);

}
int main(){
    int arr[] = {80,100,-5,70,90,20,-10,60,10,-9,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    mergesort(arr,0,n-1);
    cout<<"after mergesort, array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}