#include<iostream>
using namespace std;

int MinStepsToONE1(int n){   ///   recurrsive approach
    if(n <= 1){
        return 0;
    }
    int x = MinStepsToONE1(n-1);
    int y,z;
    y = INT16_MAX;
    z = INT16_MAX;
    if(n%2 == 0){
        y = MinStepsToONE1(n/2);
    }
    if(n%3 == 0){
        z = MinStepsToONE1(n/3);
    }
    int ans = min(x,min(y,z))+1;
    return ans;
}

int MinStepsToONE2(int n,int *arr){   ///  top-down DP (OR) Memorization  approach
    if(n <= 1){
        return 0;
    }
    if(arr[n] != 0){
        return arr[n];
    }
    int x = MinStepsToONE2(n-1,arr);
    int y,z;
    y = z = INT16_MAX;
    if(n%2 == 0){
        y = MinStepsToONE2(n/2,arr);
    }
    if(n%3 == 0){
        z = MinStepsToONE2(n/3,arr);
    }
    int ans = min(x,min(y,z))+1;
    arr[n] = ans;
    return ans;
}

int MinStepsToONE3(int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 0;
    // iterative approach which is bottom-down approach
    for(int i=2;i<=n;i++){
        int x = dp[i-1];
        int z,y;
        y = z = INT16_MAX;
        if(i%2 == 0){
            y = dp[i/2];
        }
        if(i%3 == 0){
            z = dp[i/3];
        }
        dp[i] = min(x,min(y,z)) + 1;
    }
    int ans = dp[n];
    delete []dp;
    return ans;
}
    


int main(){
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i] = 0;
    }
    cout<<MinStepsToONE2(n,arr)<<endl;
    cout<<MinStepsToONE1(n)<<endl;
    cout<<MinStepsToONE3(n)<<endl;
    return 0;
}