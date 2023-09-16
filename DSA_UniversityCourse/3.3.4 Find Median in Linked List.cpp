// Median in a Linked List
// Problem Statement
// Given a singly linked list of integers that represents a data set (with head node head), 
// return the median of the data set. The following Node class was already defined for you:
// class Node {
//     public:
//         int value;
//         Node* next = NULL;
// };

// Constraints
// The list is limited to positive numbers
// The list will not be empty
// The list is sorted

// Test cases
// We have implemented the main( ) for you. The main calls your median( ) function.

// Input: Line 1 is the number of elements in the list and Line 2 is the Linked List passed into the median( ) function. 
// Output: Median of the list, a floating point value.

// Explanation
// You will be given a set of data, integers in this case, that are all interconnected in a linked list. 
// For example, the data set 1,2,3 will given to you as the following linked list: 1->2->3. 
// Your job is to find the median of the data set. The median is defined as the value separating 
// the lower half of a data set from the upper half. In case of odd number of elements in the list, 
// the median value is the central value. In the 1->2->3 example, it was 2. 
// If the list has even number of elements, then the median will be the average of the two central values. 
// If we had 1->1->2->3, it would be (1+2)/2 = 1.5. Note you are expected to return a floating point value.

// Sample Input:
// 3
// 1->2->3

// Sample Output:
// 2.0

#include <iostream>

class Node {
    public:
        int value;
        Node* next = NULL;
};

float median(Node* head) {
    Node* faster = head;
    Node* slower = head;
    Node* previous = nullptr;
    
    while (faster != nullptr && faster->next != nullptr) {
        faster = faster->next->next;
        previous = slower;
        slower = slower->next;
    }
    
    if (faster == nullptr) { //even number of nodes
        return (slower->value + previous->value) / 2.0;
    } else { //odd number of nodes
        return static_cast<float>(slower->value);
    }

}