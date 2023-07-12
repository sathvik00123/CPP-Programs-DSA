#include<iostream>
#include<queue>
using namespace std;

void KSortedArray(int *input,int n,int k){
    priority_queue<int> pq;  /// here we used max priority queue OR max heap

    /*for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    for(int i=k;i<n;i++){
        if(pq.top() > input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }*/

    /// Another approach

    int s=0;
    while(s != n){
        pq.push(input[s]);
        if(pq.size() > k){
            pq.pop();
        }
        s++;
    }

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}

int main(){
    int input[] = {8,5,12,10,0,1,6,9};  
    KSortedArray(input,8,4);

    // for(int i=7;i>=0;i--){
    //     cout<<input[i]<<" ";
    // }
    return 0;
}