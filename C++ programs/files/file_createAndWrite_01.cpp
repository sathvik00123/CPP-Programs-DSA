#include<iostream>
#include<fstream>
using namespace std;
// file creation and writing into a file..
int main(){
    ofstream MyFile("firstfile.txt");
    MyFile << "files are tricky, but they are quite funny too...";
    MyFile.close();
    ifstream MyReadFile("firstfile.txt");
    MyReadFile.close();
    return 0;
}