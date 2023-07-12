#include<iostream>
using namespace std;

int MaxSum(int arr[],int n)
{
    int arrsum = 0;
    int currval = 0;
    for(int i=0;i<n;i++)
    {
        arrsum = arrsum + arr[i];
        currval = currval + (i*arr[i]);
    }
    int maxval = currval;
    for(int j=1;j<n;j++)
    {
        currval = currval + arrsum - n*arr[n-j];
        if(currval > maxval)
            maxval = currval;
    }
    return maxval;
}
int main()
{
    int arr[5] ={5,3,2,8,1},n;
    n = sizeof(arr)/sizeof(arr[1]);
    cout<< MaxSum(arr,n);
    return 0;
}