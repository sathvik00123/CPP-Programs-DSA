#include<bits/stdc++.h>

using namespace std;

vector<int> removeDeplicates(int a[],int n){
    vector<int> output;
    unordered_map<int, bool> mymap;

    for(int i=0;i<n;i++){
        if(mymap.count(a[i]) == 0){
            output.push_back(a[i]);
            mymap[a[i]] = true;
        }
    }
    return output;
}
int main(){
    int a[] = {1,2,3,2,5,4,6,5,7,7,3,2,8,2};
    vector<int> v = removeDeplicates(a,14);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}