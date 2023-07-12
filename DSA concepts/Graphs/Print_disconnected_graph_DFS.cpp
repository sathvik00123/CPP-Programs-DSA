#include<iostream>
#include<vector>
using namespace std;

void DFSprint(vector<vector<int>> v,int SV,vector<bool> &visited){
    cout<<SV<<endl;
    visited[SV] = true;
    for(int i=0;i<v.size();i++){
        if(v[SV][i] == 1 && visited[i] == false){
            DFSprint(v,i,visited);
        }
    }
}

void DFS(vector<vector<int>> matrix){
    int n = matrix.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFSprint(matrix,i,visited);
        }
    }
}

int main(){         ///  DFS -> depth first search
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
    DFS(matrix);
    // vector<bool> visited(n,false); 
    // DFSprint(matrix,0,visited);
    return 0;
}