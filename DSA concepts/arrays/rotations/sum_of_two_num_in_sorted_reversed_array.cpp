#include<bits/stdc++.h>
using namespace std;
bool CheckSum(int arr[],int m,int sum){
    int i;
    for(i=0;i<m-1;i++)
        if(arr[i]>arr[i+1])
            break;
    
    int r = (i+1)%m;
    int l = i;
    while(l!=r){
        if(arr[l] + arr[r] == sum)
            return true;
        
        if(arr[l] + arr[r] < sum)
            r = (r+1)%m;
        else l = (m+l-1)%m;
    }
    return false;
}

int main(){
    int arr[6] = {3,4,5,6,1,2},m,sum = 6;
    m = sizeof(arr)/sizeof(arr[0]);
    cout<<"[";
    for(int i=0;i<m;i++)
        cout<<arr[i]<<",";
    cout<<"\b]"<<endl;
    if (CheckSum(arr,m,sum)){
        cout<<"sum found";
    }
    else cout<<"sum not found";
    return 0;
}
