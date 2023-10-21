// Kth Largest Element in an Unsorted List

// Problem Statement
// You are given an unsorted list of numbers and are expected to retrieve the kth largest number of that list (if k = 3, then 3rd largest). 
// Write a function to find the kth largest value in a list. This function takes in two parameters: a list and an integer k.

// Given the module that we're on, it's imperative that you use a heap to do, which in C++ can be represented multiple ways. 
// The most common way is through std::priority_queue.

// You can create a max heap named pq and initialize it with the contents of a container nums by doing:
// priority_queue<int> pq(nums.begin(), nums.end());

// This will construct a priority queue with the contents of some container, which is a queue that by default places the largest number at the top. 
// It's a heap with the largest number at the root - aka a "max heap".

// If we want to create a min-heap, we have to utilize the template parameters as such:
// priority_queue<int, vector<int>, greater<int>> pq;

// What we want here is access to the third parameter. 
// By default (https://en.cppreference.com/w/cpp/container/priority_queue or http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/) 
// it will invoke the < operator (std::less), so we want to specify that we want to invoke the > operator (std::greater) to flip the order and prioritize the smallest element. 

// In order to solve this problem, you can use either a min or a max heap. One can be significantly more efficient than the other, can you figure out how? 
// (Hint: Insertions into a heap are O(log(k)) where k is the number of elements in the heap).

// Explanation
// Given the list [12, 3, 5, 7, 19], and k = 2, we want to find the 2nd largest element of the list. Thus, your function should return 12.

// Note
// The items in the list are not sorted. This is crucial
// There will be no duplicate entries
// Numbers range from INT_MIN to INT_MAX
// 1 <= k <= list.size()

// Sample Input:
// 12 19 45 -6 8
// 2

// Sample Output:
// 19

int kthlargest(vector<int>& nums, int k)
{
    std::priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 1; i < k; i++)
        pq.pop();
    return pq.top();
}
