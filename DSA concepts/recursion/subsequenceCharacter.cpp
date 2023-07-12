#include<iostream>
#include<string>
using namespace std;

void subseq1(string input,string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    subseq1(input.substr(1),output);  /// excluding
    subseq1(input.substr(1),output+input[0]);  /// including
}

void subseq2(char in[],char out[],int i){
    if(in[0] == '\0'){
        out[i] = '\0';
        cout<<out<<endl;
        return;
    }
    out[i] = in[0];
    subseq2(in+1,out,i+1);
    subseq2(in+1,out,i);
}

int main(){
    string input;
    cin>>input;
    char in[10];
    cin>>in;

    string output = "";
    subseq1(input,output);
    cout<<endl;
    char out[10]; 
    subseq2(in,out,0);
    return 0;
}