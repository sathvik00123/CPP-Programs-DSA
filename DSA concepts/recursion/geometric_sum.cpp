#include<iostream>
#include<math.h>
using namespace std;
double geoSum(int k){
    //// base case
    if(k==0){
        return 1;
    }

    return geoSum(k-1) + 1.0/pow(2,k);
}
int main(){
    int k;
    cin>>k;
    cout<<geoSum(k);
}