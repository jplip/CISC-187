# Activity 5 Hash tables

### Output
```
//student
Total Collisions: 0
Maximum Bucket Size: 1
Average Bucket Length: 0.556818

//data
Total Collisions: 7
Maximum Bucket Size: 2
Average Bucket Length: 0.556818
```

## Questions
### Part 6:
I tested the strings for the output of the recorded data.
When using student1, student2, ... the table had 0 total collisions, a maximum bucket size of 1, and an average bucket length of about 0.56.
This means that every student key was placed into a bucket with no second key in the same index.
When using data1, data2, ... the table had 7 total collisions, a maximum bucket size of 2, and the same average bucket length as the student key of about 0.56.
This means that the data key had some buckets containing a second key and had some collisions.
Although both keys start with the same word, student didn't produce collisions because the hash function multiplied the current value by 31 for every character.
A Longer prefix spreads the hash values out more compared to data key.
Both keys were still distributed throughout the hash table with an average of 0.56, which means most buckets contained one element and the hash table remained evenly distributed.


## Code
```c++
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class HashTable{
private:
    vector<list<pair<string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    //Calculate the hash table
    int hashFunction(const string& key) const{
        const int prime = 31;
        long long hash = 0;

        for(char c : key){
            hash = hash * prime + c;
        }
        return hash % capacity;
    }

    //Resizes and doubles hash table
    void rehash(){
        int oldCapacity = capacity;
        capacity = capacity * 2;

        vector<list<pair<string,int>>> oldTable = table;
        table.clear();
        table.resize(capacity);

        currentSize = 0;
        collisionCount = 0;

        for(auto &bucket : oldTable){
            for(auto &item : bucket)
                insert(item.first, item.second);
        }
    }

public:
    //Initializes hash size
    HashTable(int size = 11){
        capacity = size;
        table.resize(capacity);
        currentSize = 0;
        collisionCount = 0;
    }

    //Inserts key data
    void insert(const string& key, int value){
        int index = hashFunction(key);

        for(auto &pair : table[index]){
            if(pair.first == key) {
                pair.second = value;
                return;
            }
        }

        if(!table[index].empty())
            collisionCount++;

        table[index].push_back({key,value});
        currentSize++;

        if(loadFactor() > 0.75)
            rehash();
    }

    //Removes key data
    bool remove(const string& key){
        int index = hashFunction(key);

        for(auto it = table[index].begin(); it != table[index].end(); ++it){
            if(it->first == key){
                table[index].erase(it);
                currentSize--;
                return true;
            }
        }
        return false;
    }

    //Searches key data
    int search(const string& key) const{
        int index = hashFunction(key);

        for(auto pair : table[index]){
            if(pair.first == key)
                return pair.second;
        }
        return -1;
    }

    //Returns load factor
    double loadFactor() const{
        return (double)currentSize / capacity;
    }

    //Returns size
    int size() const{
        return currentSize;
    }

    //Returns no elements
    bool isEmpty() const{
        return currentSize == 0;
    }

    //Prints all buckets and key data
    void printTable() const{
        for(int i=0; i<capacity; i++){
            cout << i << ": ";
            for(auto pair : table[i])
                cout << "(" << pair.first << "," << pair.second << ") ";
            cout << endl;
        }
    }

    //Returns collision count
    int getCollisionCount() const{
        return collisionCount;
    }

    //Returns capacity
    int getCapacity() const{
        return capacity;
    }

    //Returns max bucket size
    int maxBucketSize() const{
        int maxSize = 0;
        for(auto &bucket : table){
            if(bucket.size() > maxSize)
                maxSize = bucket.size();
        }
        return maxSize;
    }

    //Returns average bucket length
    double averageBucketLength() const{
        int total = 0;

        for(auto &bucket : table)
            total += bucket.size();
        return (double)total / capacity;
    }
};

int main(){
    HashTable object1;

    //Insert 100 strings
    for (int i=1; i<=100; i++)
        object1.insert("data" + to_string(i), i);

    //Print
    cout << "Table Capacity: " << object1.getCapacity() << endl;
    cout << "Number of Elements: " << object1.size() << endl;
    cout << "Load Factor: " << object1.loadFactor() << endl;
    cout << "Total Collisions: " << object1.getCollisionCount() << endl;

    cout << endl;

    //Search key
    cout << "Search student1: " << object1.search("data1") << endl;
    cout << "Search student2: " << object1.search("data2") << endl;
    cout << "Search student101: " << object1.search("data101") << endl;

    cout << endl;

    //Remove key
    object1.remove("data1");
    object1.remove("data2");

    cout << "Search student1: " << object1.search("data1") << endl;
    cout << "Search student2: " << object1.search("data2") << endl;

    cout << endl;

    cout << "Maximum Bucket Size: " << object1.maxBucketSize() << endl;
    cout << "Average Bucket Length: " << object1.averageBucketLength() << endl;

    //Return 0 success
    return 0;
}
```
