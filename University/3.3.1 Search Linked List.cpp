// Search in List

// Problem Statement
// Write a function find(Node* node, int valueInput) that starts at the given node and returns 
// the index of the node with the value valueInput.  Indices start at 0.  
// Return -1 if valueInput does not exist.

// We have defined the following ﻿node C++ class for you:
// class Node {
//     public:
//         int value;
//         Node* next = NULL;
// };

// Test cases
// We have implemented the main( ) for you. The main calls your find( ) method.

// Input: Line 1 is the value you need to find and Line 2 is the Linked List passed into the find( ) method. 
// Output: Index of the found value. -1 if the value not present in the list.

#include <iostream>

class Node {
    public:
        int value;
        Node* next = NULL;
};

int find(Node* node, int valueInput) {
    int index = 0;
    while (node != nullptr) {
        if (node->value == valueInput) {
            return index;
        }
        node = node->next;
        index++;
    }
    return -1;
}