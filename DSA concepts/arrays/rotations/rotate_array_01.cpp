// time == O(n)
//auxilary space == O(n)


#include<bits/stdc++.h>
using namespace std;
int rotate(int m, int arr[],int e){
    int temp[m];
    int k = 0;
    for(int i=e; i<m; i++){
        temp[k] = arr[i];
        k++;
    }
    
    for(int i=0; i<e; i++){
        temp[k] = arr[i];
        k++;
    }

    for(int i=0; i<m; i++){
        arr[i] = temp[i];
    }

    for(int i=0; i<m; i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int arr[9] = {2,54,64,1,4,5,67,99,800};
    int n = sizeof(arr)/sizeof(int), d=4;
    rotate(n,arr,d);
    return 0;
}


// other method


// #include<bits/stdc++.h>
// using namespace std;
// int rotate(int m, int arr[],int e){
//     int temp[m] = {};
//     int k = 0;
//     for(int i=0; i<e; i++){
//         temp[k] = arr[i];
//         k++;
//     }
    
//     for(int i=0; i<m; i++){
//         arr[i] = arr[e+i];
//     }

//     for(int i=0; i<e; i++){
//         arr[m-e+i] = temp[i];
//     }

//     for(int i=0; i<m; i++){
//         cout<<arr[i]<<" ";
//     }

// }
// int main(){
//     int arr[9] = {2,54,64,1,4,5,67,99,800};
//     int n = sizeof(arr)/sizeof(int), d=4;
//     rotate(n,arr,d);
//     return 0;
// }