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

        void rehash(){
            mapNode<v>** temp = buckets;
            buckets = new mapNode<v>*[2*numBuckets];
            for(int i=0;i<2*numBuckets;i++){
                buckets[i] = NULL;
            }
            int oldBucketSize = numBuckets;
            numBuckets *= 2;
            count = 0;

            for(int i=0;i<oldBucketSize;i++){
                mapNode<v>* head = temp[i];
                while(head!=NULL){
                    string key = head->key;
                    v value = head->value;
                    insert(key,value);
                    head = head->next;
                }
            }

            for(int i=0;i<oldBucketSize;i++){
                delete temp[i];
            }
            delete[] temp;
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
                delete buckets[i];
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
            node->next = buckets[bucketIndex];
            buckets[bucketIndex] = node;
            count++;

            double loadfactor = (1.0*count)/numBuckets;
            if(loadfactor > 0.7){
                rehash();
            }
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

        double getLoadFactor(){
            return (1.0*count)/numBuckets;
        }

};
int main(){

    mymap<int> ourmap;
    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        ourmap.insert(key,value);
        cout<<ourmap.getLoadFactor()<<endl;
    }
    cout<<ourmap.size()<<endl;
    ourmap.remove("abc1");
    ourmap.remove("abc6");
    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        cout<<key<<" "<<ourmap.getValue(key)<<endl;
    }
    cout<<ourmap.size()<<endl;
    return 0;
}