#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFSprint(vector<vector<int>> v,int SV,vector<bool> &visited){
    int n = v.size();
    // vector<bool> visited(n,false); 
    queue<int> q;
    q.push(SV);
    visited[SV] = true;
    while(!q.empty()){
        int cv = q.front();
        q.pop();
        cout<<cv<<endl;   
        for(int i=0;i<n;i++){
            if(v[cv][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }

}

int BFS(vector<vector<int>> matrix){
    int n = matrix.size(),count = 0;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFSprint(matrix,i,visited);
            count++;
        }
    }
    return count;
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
    
    cout<<"Number of connected components using BFS : "<<BFS(matrix);
    return 0;
}

//0 1 1 3 3 5 5 4 4 1 0 2 2 6 6 5