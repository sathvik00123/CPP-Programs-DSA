#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq2;  /// max heap
    priority_queue<int, vector<int>, greater<int> > pq;  /// min heap
    pq.push(23);  /// O(logN) for push
    pq.push(2);
    pq.push(213);
    pq.push(54);
    pq.push(6);
    pq.push(0);

    cout<<"Size : "<<pq.size()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    cout<<"isEmpty : "<<pq.empty()<<endl;

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<"isEmpty : "<<pq.empty()<<endl;
}