#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class PriorityQueue{
    vector<T> pq;
    public:
        PriorityQueue(){

        }
        bool isEmpty(){
            return pq.size()==0;
        }
        // return the size of priority Queue - no of elements present
        int getSize(){
            return pq.size();
        }

        T getMin(){
            if(isEmpty()){
                return 0; // check for queue is empty
            }
            return pq[0];
        } 

        void insert(T element){
            pq.push_back(element);  // CBT yes, Heap not
            int CI = pq.size()-1;
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

        T removeMin(){
            if(pq.size() == 0){
                return 0;
            }
            int ans = pq[0];
            int lastIdx = pq.size()-1;
            swap(pq[0],pq[lastIdx]);
            pq.pop_back();
            int PI = 0;
            while(true){
                int minIdx = PI;  // Parent Index
                int leftchildIdx = (2*PI)+1,rightchildIdx = (2*PI)+2;
                if(leftchildIdx < pq.size() && pq[leftchildIdx] < pq[minIdx]){
                    minIdx = leftchildIdx;
                }  
                if(rightchildIdx < pq.size() && pq[rightchildIdx] < pq[minIdx]){
                    minIdx = rightchildIdx;
                }
                if(minIdx == PI){
                    break;
                }
                swap(pq[PI],pq[minIdx]);
                PI = minIdx;
           }
           return ans;
        }
};
int main(){         // this is also called heap sort...
    PriorityQueue<int> p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    return 0;
}

/// time ==> O(N log N)
/// space ==> O(N) as we are using vector