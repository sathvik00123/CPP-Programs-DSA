#include<iostream>
#include<string>
using namespace std;

int convertStringToInteger(string num,int n){
    if(n == 0){
        return 0;
    }
    int smallAns = convertStringToInteger(num,n-1);
    int largeAns = num[n-1] - '0';
    return smallAns*10 + largeAns;
}

int main(){
    string num = "12345";
    // int leng = length(num);
    cout<<convertStringToInteger(num,5);
    return 0;
}