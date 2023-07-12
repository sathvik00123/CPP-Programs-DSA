#include<iostream>
using namespace std;
int fib1(int n){    /// time O(2^n) 
    if(n == 0 || n == 1){
        return n;
    }
    // cout<<n<<" ";
    return fib1(n-1)+fib1(n-2);
}

int fib2(int n,int *arr){    /// time O(2^n) 
    if(n == 0 || n == 1){
        return n;
    }
    
    if(arr[n] != 0){
        return arr[n];
    }

    int output = fib2(n-1,arr) + fib2(n-2,arr);
    arr[n] = output;  /// store for the feature use
    return output;
}

int fib3(int n){                  /// time O(N) and space O(N)
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    int output = arr[n];
    delete []arr;
    return output;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i] = 0;
    }
    cout<<fib2(n,arr)<<endl;
    cout<<fib3(n)<<endl;
    cout<<fib1(n)<<endl;
}