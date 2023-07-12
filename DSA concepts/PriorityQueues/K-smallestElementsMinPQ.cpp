#include<iostream>
#include<queue>
using namespace std;

void KSortedArray(int *input,int n,int k){
    priority_queue<int> pq;  /// here we used max priority queue OR max heap
    priority_queue<int, vector<int>, greater<int> > MinPQ(input,input+n);  /// min heap  /// O(N) time /// this is better than below approach...

    /*priority_queue<int, vector<int>, greater<int> > MinPQ;  ///  O(NlogN) time
    for(int i=0;i<n;i++){
        MinPQ.push(input[i]);
    }*/
    
    for(int i=0;i<k;i++){
        cout<<MinPQ.top()<<" ";
        MinPQ.pop();
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