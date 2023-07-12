#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,e;

    cout<<"enter the number of vertices : "<<endl;
    cin>>n;
    cout<<"enter the number of edges : "<<endl;
    cin>>e;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    int fv,sv;
    for(int i=1;i<=e;i++){
        cin>>fv>>sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    return 0;
}