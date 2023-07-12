#include<iostream>
using namespace std;
void print(int n){
    ///  base case
    if(n==0) return;
    
    print(n-1);
    cout<<n<<" ";
}

void print2(int n){
    ///  base case
    if(n==0) return;
    
    cout<<n<<" ";
    print2(n-1);
}


int main(){
    int n;
    cin>>n;
    print(n);      ///// ascending order
    cout<<endl;
    print2(n);     ////  desending order
}