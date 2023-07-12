#include<iostream>
using namespace std;

void print(char arr[]){
    if(arr[0] == '\0'){
        return;
    }
    cout<<arr[0];
    print(arr+1);
}

void revPrint(char arr[]){
    if(arr[0] == '\0'){
        return;
    }
    revPrint(arr+1);
    cout<<arr[0];
}

void lengthArray(char arr[],int &count){
    if(arr[0] == '\0'){
        return;
    }
    count++;
    lengthArray(arr+1,count);
}

int lengthArray1(char arr[]){
    if(arr[0] == '\0'){
        return 0;
    }
    return 1 + lengthArray1(arr+1);
}


int main(){
    char arr[] = "sathvik";
    print(arr);
    cout<<endl;
    revPrint(arr);
    cout<<endl;
    int count = 0;
    lengthArray(arr,count);
    cout<<"length : "<<count<<endl;
    cout<<"length : "<<lengthArray1(arr);
    return 0;
}