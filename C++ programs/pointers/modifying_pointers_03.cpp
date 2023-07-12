#include<iostream>
#include<string>
using namespace std;

int main(){
    int number = 34;
    int* ptr = &number;
    cout << number << "\n";
    cout << &number << "\n";
    cout << ptr << "\n";
    *ptr = 345;
    cout << *ptr << "\n";
    cout << number << "\n";
    cout << ptr << "\n";
    cout << &number;
    return 0;
}