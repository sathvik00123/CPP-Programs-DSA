#include<iostream>
#include<string>
using namespace std;

template<typename v>
class mapNode{
  public:
    string key;
    v value;
    mapNode* next;

    mapNode(string key,v value){
        this->value = value;
        this->key = key;
        next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};

template<typename v>
class mymap{
    private:
        mapNode<v>** buckets;
        int count;
        int numBuckets;

        int getBucketIndex(string key){
            int hashcode = 0;
            int base = 1;
            int p = 37;
            for(int i=key.size()-1;i>=0;i--){
                hashcode += key[i] + base;
                base = base*p;
                hashcode = hashcode % numBuckets;
                base = base % numBuckets;
            }
            return hashcode % numBuckets; 
        }
    public:
        mymap(){
            count = 0;
            numBuckets = 5;
            buckets = new mapNode<v>*[numBuckets];
            for(int i=0;i<numBuckets;i++){
            buckets[i] = NULL;
            }
        }
        ~mymap(){
            for(int i=0;i<numBuckets;i++){
                delete bucket[i];
            }
            delete[] buckets;
        }

        int size(){
            return count;
        }

        v getValue(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<v>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head->key == key){
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }

        void insert(string key,v value){
            int bucketIndex = getBucketIndex(key);
            mapNode<v>* head = buckets[bucketIndex];
            while(head != NULL){
                if(head -> key == key){
                    head -> value = value;
                    return;
                }
            }
            mapNode<v>* node = new mapNode<v>(key,value);
            node->node = buckets[bucketIndex];
            buckets[bucketIndex] = node;
            count++;
        }

        v remove(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<v>* head = buckets[bucketIndex];
            mapNode<v>* prev = NULL;
            while(head != NULL){
                if(head->key == key){
                    if(prev == NULL){
                        buckets[bucketIndex] = head->next;
                    }
                    else{
                        prev->next = head->next;
                    }
                    v value = head->value;
                    head->next = NULL;
                    delete head;
                    count--;
                    return value;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }

};
int main(){
    return 0;
}