#include<iostream>
using namespace std;

int length(char input[]){
    int count = 0;
    for(int i=0;input[i] != '\0';i++){
        count++;
    }
    return count;
}

void reverse(char input[]){
    int s = 0,e = length(input)-1;
    while(s<e){
        swap(input[s],input[e]);
        s++;
        e--;
    }
}

int main(){
    char name[100];
    cout<<"Enter the characters : ";
    cin.getline(name,100);
    cout<<"The entered characters :"<<name<<endl;
    cout<<"length of the characters: "<<length(name)<<endl;
    reverse(name);
    cout<<"reversed characters array: "<<name;
    return 0;
}