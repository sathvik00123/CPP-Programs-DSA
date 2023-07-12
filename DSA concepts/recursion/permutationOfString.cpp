#include<iostream>
#include<string>
using namespace std;
void permute1(char str1[],int i){
    if(str1[i] == '\0'){
        cout<<str1<<endl;
        return;
    }

    for(int j = i;str1[j] != '\0';j++){
        swap(str1[i],str1[j]);
        permute1(str1,i+1);
        swap(str1[i],str1[j]);
    }
}

void permute2(string str,int l,int r){
    if(l == r){
        cout<<str<<endl;
        return;
    }
    for(int i=l;i<=r;i++){
        swap(str[l],str[i]);
        permute2(str,l+1,r);
        swap(str[l],str[i]);
    }
}
int main(){
    char str1[] = "abc";
    string str = "abc";
    permute1(str1,0);
    cout<<endl;
    permute2(str,0,str.length()-1);
    return 0;
}