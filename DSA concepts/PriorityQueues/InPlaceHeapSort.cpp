#include<iostream>
using namespace std;

void inplaceHeapSort(int *pq,int n){
    // Build the heap in input array

    for(int i=1;i<n;i++){
        int CI = i;
        while(CI > 0){
                int PI = (CI - 1)/2;
                if(pq[CI]<pq[PI]){
                    swap(pq[CI],pq[PI]); 
                    CI = PI;
                }else{
                    break;
                }
            }
    }

    /// Remove min n times
    int size = n;
    while(size>=1){
        swap(pq[0],pq[size-1]);
        size--;  ///  Assumption that element is removed at end...
        /// down heapify
        int PI = 0;
        while(true){
            int minIdx = PI;  // Parent Index
            int leftchildIdx = (2*PI)+1,rightchildIdx = (2*PI)+2;
            if(leftchildIdx < size && pq[leftchildIdx] < pq[minIdx]){
                minIdx = leftchildIdx;
            }  
            if(rightchildIdx < size && pq[rightchildIdx] < pq[minIdx]){
                minIdx = rightchildIdx;
            }
            if(minIdx == PI){
                break;
            }
            swap(pq[PI],pq[minIdx]);
            PI = minIdx;
        }
    }
}
int main(){
    int input[] = {5,1,2,0,8};
    inplaceHeapSort(input,5);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }  
    return 0;
}

/// time ==> O(N log N)
/// space ==> O(1)