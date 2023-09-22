// Interquartile Range

// Problem Statement
// Given a sorted singly linked list without a tail (e.g, head (1) -> (2) -> (3) -> (4)), 
// return the interquartile range of the data set using the slow and fast pointer approach 
// OR using a methodology that does not iterate over the linked list twice. 
// You must not iterate over the entire linked list more than once and 
// you cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem. 
// You must not use more than one loop for this problem.

// The following Node class is already defined for you and 
// we have already implemented the insert() and main() function.
// class Node {
//     public:
//         int value;
//         Node* next = nullptr;
// };

// Example 1 Input: 2 4 4 5 6 7 8
// Example 1 Output: 3.00

// Input is a set of numbers inserted into a Linked List separated by spaces.
// The head of this linked list is passed into the interQuartile() function.
// Output is the Interquartile Range of the list, a floating point value. 
// IQR = Q3-Q1 = 7-4 = 3.00. We are rounding returned values to two decimal places in main using setprecision().

// Note you are expected to return a floating point value. 
// Also, there are a a variety of definitions of IQR and we will use the definition listed here: 
// https://www.calculatorsoup.com/calculators/statistics/quartile-calculator.php
// You can use the calculator at above link to generate sample test cases.

// Constraints
// The list can contain any integers.
// The list will have at least 4 values.
// The list is sorted.

#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key) {
    Node* temp = new Node();
    temp->value = key;
    if (head == nullptr) {
        head = temp;
    } else {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head) {
    Node *faster = head, *q1 = head, *q3 = head;
    Node *q1previous = nullptr, *q3previous = nullptr;
    int counter = 0;

    // Iterate over list once using slow/fast pointer technique
    while (faster != nullptr && faster->next != nullptr) {
        faster = faster->next->next;
        q3previous = q3;
        q3 = q3->next; 

        counter++;
        if (counter % 2 == 0) { 
            q1previous = q1;
            q3previous = q3;
            q1 = q1->next;
            q3 = q3->next;
        }
    }
    
    float Q1, Q3;
    if (faster == nullptr) { //even number of nodes
        if (counter % 2 == 1) { // 6, 10, 14, 18, .., nodes
            Q1 = q1->value;
            Q3 = q3->value;
        } else { // 4, 8, 12, 16, .., nodes
            Q1 = (q1->value + q1previous->value) / 2.0f;
            Q3 = (q3->value + q3previous->value) / 2.0f;
        }
    } else { //odd number of nodes
        if (counter % 2 == 1) { // 7, 11, 15, 19, .., nodes
            Q1 = q1->value;
            Q3 = q3->next->value;
        } else { // 5, 9, 13, 17, .., nodes
            Q1 = (q1->value + q1previous->value) / 2.0f;
            Q3 = (q3->value + q3->next->value) / 2.0f;
        }
    }
    return Q3 - Q1;
}