// Add Node to a List

// Problem Statement
// Write a function add(Node* head, int index, int value) to add a node to a linked list.  
// The head of the linked list is input, as well as the index where the node should be added 
// and the value associated with the node.  The program returns the head of the updated list.  
// If the index of insertion is greater than the size of the list, the program should return NULL.

// We have defined the following node C++ class for you:
// class Node {
//     public:
//         int value;
//         Node* next = NULL;
// };

// The program input is a value, an index, and a list.

// Test cases
// We have implemented the main( ) for you. The main calls your add( ) method.

// Input:
// Line 1 has three integers.
// Integer 1 is the size of the list. This value is not passed into the function and is not accessible to you.
// Integer 2 is the value to be inserted.
// Integer 3 is the position at which the value needs to be inserted.
// Line 2 is the Linked List passed into the add( ) method with nodes separated by a space. 

// Output: Traversal of the updated list.

// Sample Input:
// 4 5 1
// 0 1 2 3

// Sample Output:
// 0 5 1 2 3 

#include <iostream>

class Node {
    public:
        int value;
        Node* next = NULL;
};

Node* add(Node* head, int index, int valueInput) {
    Node* newNode = new Node();
    newNode->value = valueInput;
    Node* currentNode = head;

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }

    int counter = 0;
    while (currentNode != nullptr) {
        if (counter == index-1) {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return head;
        }
        currentNode = currentNode->next;
        counter++;
    }

    return nullptr;
}