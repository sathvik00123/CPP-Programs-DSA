#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> v,int SI,vector<bool> &visited){
    cout<<SI<<endl;
    visited[SI] = true;
    for(int i=0;i<v.size();i++){
        if(v[SI][i] == 1 && visited[i] == false){
            print(v,i,visited);
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
    vector<bool> visited(n,false); 
    print(matrix,0,visited);
    return 0;
}