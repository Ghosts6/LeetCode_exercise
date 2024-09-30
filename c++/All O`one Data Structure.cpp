#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <list>

class AllOne {
private:
    struct Bucket {
        int count;
        std::unordered_set<std::string> keys;
    };

    std::list<Bucket> buckets; 
    std::unordered_map<std::string, int> keyCount;  
    std::unordered_map<int, std::list<Bucket>::iterator> countBucket; 

    std::list<Bucket>::iterator addBucketAfter(std::list<Bucket>::iterator it, int count) {
        auto newBucket = buckets.insert(std::next(it), {count, {}});
        countBucket[count] = newBucket;  
        return newBucket;
    }

    void removeBucketIfEmpty(std::list<Bucket>::iterator it) {
        if (it->keys.empty()) {
            countBucket.erase(it->count);  
            buckets.erase(it);  
        }
    }

public:
    AllOne() {}

    void inc(std::string key) {
        int currentCount = keyCount[key]; 
        keyCount[key] = currentCount + 1;

        std::list<Bucket>::iterator currentBucket;

        if (currentCount > 0) {
            currentBucket = countBucket[currentCount];
            currentBucket->keys.erase(key); 
            removeBucketIfEmpty(currentBucket);  
        }

        int newCount = currentCount + 1; 
    
        if (countBucket.find(newCount) != countBucket.end()) {
            currentBucket = countBucket[newCount];  
        } else {
            currentBucket = (currentCount == 0) ? buckets.begin() : countBucket[currentCount];
            currentBucket = addBucketAfter(currentBucket == buckets.end() ? buckets.begin() : currentBucket, newCount);
        }
        currentBucket->keys.insert(key);  
    }

    void dec(std::string key) {
        int currentCount = keyCount[key];
        if (currentCount == 0) return; 

        keyCount[key] = currentCount - 1;  
        std::list<Bucket>::iterator currentBucket = countBucket[currentCount];
        currentBucket->keys.erase(key);  
        removeBucketIfEmpty(currentBucket); 

        if (currentCount == 1) {
            keyCount.erase(key);  
            return;
        }

        int newCount = currentCount - 1;

        if (countBucket.find(newCount) != countBucket.end()) {
            currentBucket = countBucket[newCount];  
        } else {
            if (currentBucket != buckets.begin()) {
                currentBucket = addBucketAfter(std::prev(currentBucket), newCount);  
            } else {
                currentBucket = buckets.insert(buckets.begin(), {newCount, {}});  
                countBucket[newCount] = currentBucket;
            }
        }
        currentBucket->keys.insert(key); 
    }

    std::string getMaxKey() {
        if (buckets.empty()) return ""; 
        return *(buckets.back().keys.begin());  
    }

    std::string getMinKey() {
        if (buckets.empty()) return "";  
        return *(buckets.front().keys.begin());  
    }
};
// Test case       
int main() {
    AllOne* obj = new AllOne();

    obj->inc("apple");
    obj->inc("banana");
    obj->inc("apple");
    obj->inc("orange");
    obj->inc("banana");
    obj->inc("banana");
    obj->inc("apple");

    std::cout << "Max Key: " << obj->getMaxKey() << std::endl; 
    std::cout << "Min Key: " << obj->getMinKey() << std::endl;  

    obj->dec("banana");
    std::cout << "Max Key after dec: " << obj->getMaxKey() << std::endl;  
    std::cout << "Min Key after dec: " << obj->getMinKey() << std::endl;  

    obj->dec("banana");
    obj->dec("banana");
    std::cout << "Max Key after more dec: " << obj->getMaxKey() << std::endl;  
    std::cout << "Min Key after more dec: " << obj->getMinKey() << std::endl; 
    
    delete obj;
    return 0;
}
