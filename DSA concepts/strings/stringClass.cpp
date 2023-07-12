#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "abcd";
    cout<<s1<<endl;

    string s2;
    s2 = "dcba";
    cout<<s2<<endl;

    string *s3 = new string;
    *s3 = "fsaaab";
    cout<<s3<<endl;
    cout<<*s3<<endl;

    vector<string> v;
    v.push_back("amazing");
    v.push_back(s2);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
        sort(v[i].begin(),v[i].end());
        cout<<v[i]<<endl;
    }

    // string s4;
    // getline(cin,s4);  // cin won't work for spaces, tabs, /n .... instead we use getline.
    // cout<<s4<<endl;
    cout<<endl;
    string s5;
    s5 = "aasbbc";
    cout<<s5[0]<<endl;
    s5[0] = 'Q';
    cout<<s5<<endl;

    cout<<endl;

    string s6 = "";
    s6 += s1 + s2 + " hello";
    cout<<s1<<endl;  // s1 = abcd
    cout<<s2<<endl;  // s2 = dcba
    cout<<s6<<endl;
    cout<<s6.size()<<endl;
    cout<<s6.length()<<endl;
    
    cout<<s6.substr(3)<<endl;
    string s7 = s6.substr(3,3); // first 3 is for start index and second 3 is number of characters after start index...
    cout<<s7<<endl;

    string s8 = "acbababcdbcabc";
    cout<<s8.find("abc")<<endl;

    int a = 1243;
    string s9 = to_string(a);
    cout<<s9<<endl;
    // s9[1] = 'S';
    s9[3] = 'A';
    cout<<s9<<endl;
    
    string s10 = "1234";
    s10.push_back('5');
    cout<<s10<<endl;

    a = atoi(s9.c_str());  //  atoi function is used to convert string to interger...
    cout<<a<<endl;
    a = atoi(s10.c_str()); 
    cout<<a<<endl;
    return 0;
}