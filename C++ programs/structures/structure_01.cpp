#include<iostream>
#include<string>
using namespace std;
// using mutiple variables in under a single structure...
int main(){
    struct{
        int year;
        string name;
        float milage;
        }Bike1,Bike2,Bike3;
        
    Bike1.name = "TVS-apache";
    Bike1.year = 1993;
    Bike1.milage = 47.234;
    cout <<"Bike1 data in the showroom...\n";
    cout << "name --> " << Bike1.name <<"\nyear --> "<< Bike1.year << "\nMilage --> " << Bike1.milage << endl;
    Bike2.name = "TVS-apache";
    Bike2.year = 2001;
    Bike2.milage = 40.543;
    cout << endl <<"Bike2 data in the showroom...\n";
    cout << "name --> " << Bike2.name <<"\nyear --> "<< Bike2.year << "\nMilage --> " << Bike2.milage << endl;
    Bike3.name = "YAMAHA";
    Bike3.year = 1999;
    Bike3.milage = 32.89;
    cout << endl <<"Bike3 data in the showroom...\n";
    cout << "name --> " << Bike3.name <<"\nyear --> "<< Bike3.year << "\nMilage --> " << Bike3.milage;
    return 0;
}