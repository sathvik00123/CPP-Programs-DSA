#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> mymap;
    mymap["abc1"] = 1;
    mymap["abc2"] = 2;
    mymap["abc3"] = 3;
    mymap["abc4"] = 4;
    mymap["abc5"] = 5;
    mymap["abc6"] = 6;

    for(unordered_map<string,int>::iterator it = mymap.begin(); it != mymap.end(); it++){
        cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
    }
    cout<<endl;
    for(auto it = mymap.begin(); it != mymap.end(); it++){  // any datatype can be given by auto...
        cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
    }
    cout<<endl;

    map<string,int> mymap1;  /// map will(keys) sort according to BST order ...
    mymap1["abc3"] = 3;
    mymap1["abc6"] = 60;
    mymap1["abc5"] = 5;
    mymap1["abc2"] = 20;
    mymap1["abc4"] = 4;
    mymap1["abc1"] = 1;
    for(map<string,int>::iterator it = mymap1.begin(); it != mymap1.end(); it++){
        cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
    }

    cout<<endl;

    vector<int> v;
    v.push_back(23);
    v.push_back(56);
    v.push_back(2121);
    v.push_back(76);   
    v.push_back(978);
    v.push_back(1);

    for(vector<int>::iterator it = v.begin(); it < v.end(); it++){
        cout<<*it<<endl;
    }
    cout<<endl;

    for(vector<int>::iterator it = v.begin(); it < v.end(); it++){
        cout<<*it<<endl;
    }
    cout<<endl;
    mymap.erase(mymap.begin(),mymap.end());
     
    // find pair present or not...
    if(mymap.find("abc") == mymap.end()){
        cout<<"Not present"<<endl;
    }else{
        cout<<"Present"<<endl;
    }

    for(auto it = mymap.begin(); it != mymap.end(); it++){
        cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
    }
    cout<<endl;
    cout<<mymap.size()<<endl;
    cout<<endl;
    auto a = 89;
    cout<<a<<endl;

    auto b = "AdsSfCXCS";
    cout<<b<<endl;
    return 0;
}