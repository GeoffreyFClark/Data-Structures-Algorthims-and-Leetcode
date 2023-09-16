// Implementing a Stack using a Linked List
// In this problem you will be implementing a Stack using a Singly Linked List. 
// Implement the following functionalities of a stack ADT using a singly linked list.

// push(x) -- Push element x on the stack.
// pop() -- Remove the element from the top of the stack.
// peek() -- Return the element at the top of the stack.
// isEmpty() -- Return whether the stack is empty.

// Constraints
// The values in the stack are integers, i.e. x is an integer.

// Note
// Your Stack implementation (class Stack_LL) should use the Node Class given below to build your Singly Linked List.
// class Node {
// public:
// 	int data;
// 	Node* next;
// 	Node(int val) {data = val; next = nullptr;}
// 	Node(int val, Node* node) {data = val; next = node;}
// };
 
// Hint
// topPtr is a pointer that points to the top element of the stack. You could treat it as a head pointer for your linked list implementation. topPtr is a private data member that is available in the Stack_LL class.

// Test cases
// We will be testing your code and implementing the main( ) function. A description of the test cases is given below.

// The first line of the input is the operation we will be calling on your Stack object.
// The second line of input is the parameters that are passed to the corresponding operation in Line 1.
// The Output is the return value of the function call to the corresponding operation in Line 1. null in output means the function doesn't return anything. They are of type void. 
// You may assume that all operations are valid (e.g. no pop or peek operations will be called on an empty stack).

// Sample Input:
// [push,push,pop,peek,push,push,peek,isEmpty]
// [[1],[2],[],[],[4],[12],[],[]]

// Sample Output:
// [null, null, null, 1, null, null, 12, false]

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int val) {data = val; next = nullptr;}
        Node(int val, Node* node) {data = val; next = node;}
};

class Stack_LL {
    private:
        Node* topPtr; // topPtr points to the top element of the stack
    public:
        Stack_LL();
        ~Stack_LL();

        bool isEmpty() const;
        void push(int newItem);
        void pop();
        int peek() const;
};

Stack_LL::Stack_LL() {
    topPtr = nullptr;
}

Stack_LL::~Stack_LL() {
    while (!isEmpty()) {
        pop();   
    }
}

bool Stack_LL::isEmpty() const {
    return topPtr == nullptr;
}

void Stack_LL::push(int newItem) {
    Node* newNode = new Node(newItem);
    newNode->next = topPtr;
    topPtr = newNode;
}

void Stack_LL::pop() {
    Node* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
}

int Stack_LL::peek() const {
    return topPtr->data;
}