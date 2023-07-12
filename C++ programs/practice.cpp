#include <iostream>
using namespace std;

int leftRot(int arr[], int n, int d){
    int A[] = {},B[] = {};
    for(int i=0;i<d;i++){
        A[i] = arr[i];
		cout<<A[i]<<" ";
    }
    // for(int i=d;i<n;i++){
    //     B[i] = arr[i];
    // }
	// for(int i=0;i<d;i++){
    //     cout<<A[i]<<" ";
    // }
}
int main() {
	int arr[8] = {1,2,3,4,5,6,7,8},d=3;
    int n = sizeof(arr)/sizeof(arr[0]);
    leftRot(arr,n,d);
	return 0;
}

