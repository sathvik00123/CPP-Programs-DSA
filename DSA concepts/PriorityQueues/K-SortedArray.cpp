#include<iostream>
#include<queue>
using namespace std;

void KSortedArray(int *input,int n,int k){
    priority_queue<int> pq;  /// here we used max priority queue OR max heap

    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    int s = 0;
    for(int i=k;i<n;i++){
        input[s] = pq.top();
        pq.pop();
        s++;
        pq.push(input[i]);
    }

    while(!pq.empty()){
        input[s] = pq.top();
        pq.pop();
        s++;
    }
}

int main(){
    int input[] = {12,7,5,9,4};  // this is K sorted array
    KSortedArray(input,5,3);

    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}