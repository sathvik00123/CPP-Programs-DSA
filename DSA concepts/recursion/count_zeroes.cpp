#include<iostream>
using namespace std;
int count(int n){
    ///base case...
    if(n==0){
        return 0;
    }

    int last_digit = n%10;
    if(last_digit==0) return 1 + count(n/10);
    else return count(n/10);
}
int main(){
    int n;
    cin>>n;
    cout<<count(n);
}