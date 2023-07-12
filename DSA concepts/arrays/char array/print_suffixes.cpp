#include<iostream>
using namespace std;
int length(char str2[]){
    int count = 0;
    for(int i=0;str2[i] != '\0';i++){
       count++;
    }
    return count;
}

void printSuffixes(char str2[]){
    for(int e=length(str2)-1;e>=0;e--){
        for(int s=e;s<length(str2);s++){
            cout<<str2[s];
        }
        cout<<endl;
    }
}

int main(){
    char str1[100];
    cin>>str1;
    printSuffixes(str1);
    return 0;
}