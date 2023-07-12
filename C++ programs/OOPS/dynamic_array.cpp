#include<iostream>
using namespace std;
class dynamicArray{
    int *data;
    int nextindex;
    int capacity;

    public:
    dynamicArray(){
        data = new int[5];
        nextindex = 0;
        capacity = 5;
    }
    void add(int element){
        if(nextindex == capacity){
            int *newdata = new int[capacity*2];
            for(int i=0;i<capacity;i++){
                newdata[i] = data[i];
            }
            delete []data;
            data = newdata;
            capacity = capacity*2;
        }
        data[nextindex] = element;
        nextindex ++; 
    }

    void add(int element,int i){
        if(i<nextindex){
            data[i] = element;
        }
        else if(i==nextindex){
            add(element);
        }
        else{
            return;
        }
    }

    int get(int i){
        if(i>=0 && i<nextindex){
            return data[i];
        }
        else{
            return -1;
        }
    }

    void print(){
        for(int i=0;i<nextindex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    int getCapacity(){
        return capacity;
    }
};
int main(){
    dynamicArray d1;  // default constructor
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();
    cout<<d1.getCapacity()<<endl;
    
    return 0;
}