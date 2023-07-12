// // Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     for(int k=0;k<t;k++){
//         int m,n,value=0;
//         cin>>m>>n;
//         int arr[m][n];
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 cin>>arr[i][j];
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(arr[i][j] == 0){
//                          for(int i=0;i<m;i++){
//                             arr[i][j] = 0;
//                         }
//                         for(int j=0;j<n;j++){
//                             arr[i][j] = 0;
//                         }
                        
//                     }
//                 }
//             }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 cout<<arr[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;
// int main(){
//     cout<<"hello" * 4;
//     return 0;
// }


#include<iostream>
using namespace std;
void fun(int n){
    if(n == 0){
        return;
    }
    cout<<n<<endl;
    fun(n-1);
    cout<<n<<endl;
}
int main(){
    fun(4);
    return 0;
}