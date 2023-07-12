#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    unordered_map<string,int> mymap;
    /// inserting into map...
    pair<string,int> p("abc",1);
    mymap.insert(p);

    mymap["def"] = 2;
    cout<<mymap["abc"]<<endl;
    cout<<mymap.at("def")<<endl;
    cout<<"size "<<mymap.size()<<endl;

    // cout<<mymap.at("ghi")<<endl;  // throws exception.
    cout<<mymap["ghi"]<<endl;  

    cout<<"size "<<mymap.size()<<endl;
    // check key is present or not.
    if(mymap.count("ghi") > 0){
        cout<<"ghi found"<<endl;
    }else{
        cout<<"ghi not found"<<endl;
    }
    // update
    mymap["abc"] = 10;
    cout<<"abc updated value "<<mymap["abc"]<<endl;  
    // erase OR delete
    mymap.erase("ghi");
    cout<<"size "<<mymap.size()<<endl;

    if(mymap.count("ghi") > 0){
        cout<<"ghi found"<<endl;
    }else{
        cout<<"ghi not found"<<endl;
    }
    return 0;
}