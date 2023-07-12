#include<iostream>
using namespace std;
class complexnumbers{
    private:
        int real;
        int image;
    public:
    complexnumbers(int real,int image){
        this->real = real;
        this->image = image;
    }
    void add(complexnumbers c2){
        real = real + c2.real;
        image = image + c2.image;
    }
    void multiply(complexnumbers c2){
        real = (real*c2.real) - (image*c2.image);
        image = (real*c2.image) + (image*c2.real);
    }
    void print(){
        cout<<real<<"+"<<image<<"i"<<endl;
    }
};
int main (){
    int real1,real2,image1,image2;
    cin>>real1>>image1;
    cin>>real2>>image2;
    
    complexnumbers c1(real1,image1);
    complexnumbers c2(real2,image2);

    int choice;
    cin>>choice;
    if(choice == 1){
        c1.add(c2);
        c1.print();
    }
    else if(choice == 2){
        c1.multiply(c2);
        c1.print();
    }
    else{
        return 0;
    }
    return 0;
}