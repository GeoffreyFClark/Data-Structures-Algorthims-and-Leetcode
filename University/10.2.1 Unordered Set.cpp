// Unordered Set Implementation

// Implement an unordered set (a container for unique members) for integers in C++. It should support the following functions:
// void insert(val): Adds a value into the set
// bool has(val): Returns true if a value exists in the set, false otherwise.
// void rem(val): Removes a value from the set. If the value is not present, don't do anything.
// int size(): Returns the size of the set

// All of these functions should be O(1) on average. Think about what was covered in class, specifically with hash function design and collision resolution protocols.

// Sample Input:
// get size
// insert x
// get size
// has x
// insert x
// get size
// remove x
// get size
// has x
// insert 1-10000
// get size
// insert 1-10000
// get size
// has 1-10000
// remove 1-10000
// get size

// Sample Output:
// 0
// 1
// true
// 1
// 0
// false
// Commencing stress test...
// 10000
// 10000
// 0


// Submission #1, met requirements
// #include <vector>
// #include <list>
// #include <functional>
// #include <algorithm>
// using namespace std;

// // O(1) operations on unordered set
// class unorderedSet {
// private:
//     vector<list<int>> buckets; // vector of buckets, each bucket is a list to handle collisions
//     size_t count; // num of unique elements in set
    
//     // using hardcoded 107 buckets in this example, but could add function to rehash once a certain load factor is reached
//     const int BUCKET_COUNT = 107; 
    
//     size_t getBucketIndex(int val) const {
//         // using C++ standard library hash then modulo bucket count
//         size_t hashValue = hash<int>{}(val);
//         return hashValue % BUCKET_COUNT;
//     }
// public:
//     // initializer
//     unorderedSet() {
//         count = 0;
//         buckets.resize(BUCKET_COUNT); 
//     }

//     // Inserts unique value into set, ensuring no duplicate
//     void insert(int val) {
//         if (!has(val)) { 
//             buckets[getBucketIndex(val)].push_front(val);
//             count++;
//         } 
//     }

//     // Check if value exists in set
//     bool has(int val) {
//         auto& bucket = buckets[getBucketIndex(val)];
//         return find(bucket.begin(), bucket.end(), val) != bucket.end();
//     }

//     // Removes value from set if it exists
//     void rem(int val) {
//         auto& bucket = buckets[getBucketIndex(val)];
//         auto iter = find(bucket.begin(), bucket.end(), val);
//         if (iter != bucket.end()) {
//             bucket.erase(iter);
//             count--;
//         }
//     }

//     // Returns num of unique elements in the set
//     int size() {
//         return count;
//     }
// };



// Submission #2, decided to implement a rehash function
#include <vector>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

// Custom unordered set implementation with rehashing capability
class unorderedSet {
private:
    vector<list<int>> buckets; // Vector of buckets where each bucket is a list to handle collisions
    int count; 
    int bucket_count; 
    const double MAX_LOAD_FACTOR = 0.75; // Load factor threshold for rehashing

    // Hash function to compute bucket index
    int getBucketIndex(int val) const {
        size_t hashValue = hash<int>{}(val); // Standard library hash function
        return static_cast<int>(hashValue % bucket_count); // Modulo operation to get the bucket index
    }

    // Rehash set when load factor exceeds threshold
    void rehash() {
        int new_bucket_count = bucket_count * 2; // Double the number of buckets
        vector<list<int>> new_buckets(new_bucket_count);

        // Rehash all existing elements into the new buckets
        for (int i = 0; i < buckets.size(); ++i) {
            for (auto iter = buckets[i].begin(); iter != buckets[i].end(); ++iter) {
                int new_index = getBucketIndex(*iter) % new_bucket_count;
                new_buckets[new_index].push_front(*iter);
            }
        }

        buckets = move(new_buckets); // Replace old buckets with the new ones
        bucket_count = new_bucket_count; // Update the bucket count
    }

public:
    // initializer with 10 buckets
    unorderedSet() {
        count = 0;
        bucket_count = 10; 
        buckets.resize(bucket_count); 
    }

    // Inserts unique value into set, ensuring no duplicate
    void insert(int val) {
        if (!has(val)) { // Only insert if not already present
            if ((double)count / bucket_count > MAX_LOAD_FACTOR) {
                rehash(); // Rehash if load factor is exceeded
            }
            int index = getBucketIndex(val);
            buckets[index].push_front(val); // Insert the value into the appropriate bucket
            count++;
        }
    }

    // Check if value exists in set
    bool has(int val) const {
        int index = getBucketIndex(val);
        const auto& bucket = buckets[index];
        return find(bucket.begin(), bucket.end(), val) != bucket.end(); // Use standard find algorithm
    }

    // Removes value from the set if it exists
    void rem(int val) {
        int index = getBucketIndex(val);
        auto& bucket = buckets[index];
        auto iter = find(bucket.begin(), bucket.end(), val); // Find the element in the bucket
        if (iter != bucket.end()) {
            bucket.erase(iter); // Erase if found
            count--;
        }
    }

    // Get the number of elements in the set
    int size() const {
        return count;
    }
};
