// n-Ary Tree Preorder Traversal

// Problem Statement
// Given the root node of an N-ary tree, create a function to print out the preorder traversal of its nodes' values. 
//The function will have the following signature:
// void preorder(Node* root)

// We have defined the following Node C++ class for you:
// class Node {
// public:
//    int val;
//    vector<Node*> children;
//    Node() {}
//    Node(int _val) {
//       val = _val;
//    }
//    Node(int _val, vector<Node*> _children) {
//       val = _val;
//       children = _children;
//    }
// };
 

// Example 1:
// Input: [12,null,1,4,5,null,null,7,11,null,8]
// Output: 12 1 4 7 11 5 8

// Example 2: 
// Input:​[1,null,2,3,4,null,5,6,null,7]
// Output: 1 2 5 6 3 7 4 
 
// Test Cases
// Input represents the level order traversal of an N-ary Tree. Each group of children, from left to right, is separated by a null value. Each level is separated by a null value.
// In your preorder method implementation, you will print the nodes' values at each level with the level number.
// In our main method, we will directly call preorder method. We expect the output of your preorder to match the above format. 

// Note
// You do not need to implement a main function or the Node class. You are only required to implement the preorder function. We have created a main method that tests your preorder function.

// Sample Input:
// [12,null,1,4,5,null,null,7,11,null,8]

// Sample Output:
// 12 1 4 7 11 5 8 

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

class Node {
public:
   int val;
   vector<Node*> children;
   Node() {}
   Node(int _val) {
      val = _val;
   }
   Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
   }
};

void preorder(Node* root) {
    cout << root->val << " ";
    for (int i=0; i < root->children.size(); i++){
        preorder(root->children[i]);
    }
}