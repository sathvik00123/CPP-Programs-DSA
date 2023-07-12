#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> *vp = new vector<int>();  //// dynamical vector...
    vector<int> v1;  /// statical vector...
    
    v1.push_back(23);
    v1.push_back(21);
    v1.push_back(265);
    v1.push_back(6544);
    cout<<v1[0]<<" ";
    cout<<v1[1]<<" ";
    cout<<v1[2]<<" ";
    cout<<v1[3]<<" ";
    cout<<endl;
    cout<<v1.at(2)<<endl;
    v1[1] = 143;

    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    sort(v1.begin(),v1.end());

    vector<int> v2;
    for(int i=0;i<100;i++){
        v2.push_back(i+1);
    }
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }

    vector<int> v3;
    for(int i=0;i<100;i++){
        v3.push_back(i+1);
        cout<<"size : "<<v3.size()<<endl;
        cout<<"capacity : "<<v3.capacity()<<endl;
    }

    return 0;
}