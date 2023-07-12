#include<iostream>
using namespace std;

void printPrefixes(char charArr[]){
    for(int e=0;charArr[e] != '\0';e++){
        for(int s=0;s<=e;s++){
            cout<<charArr[s];
        }
        cout<<"\n";
    }
}

int main(){
    char str[100];
    cin>>str;
    printPrefixes(str);
    return 0;
}