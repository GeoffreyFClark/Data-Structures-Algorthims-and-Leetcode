// n-Ary Tree Level Order Traversal

// Problem Statement
// Given the root node of an N-ary tree, create a function to print out the level order traversal of its nodes' values. 

// The function will have the following signature:
// void levelOrder(Node* root)

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
// Input: 
// [12,null,1,4,5,null,null,7,11,null,8]
// Output:
// Level: 1
// 12 
// Level: 2
// 1 4 5 
// Level: 3
// 7 11 8 

// Example 2: 
// Input:
// [1,null,2,3,4,null,5,6,null,7]
// Output:
// Level: 1
// 1 
// Level: 2
// 2 3 4 
// Level: 3
// 5 6 7
 
// Test Cases
// Input represents the level order traversal of an N-ary Tree. Input represents the level order traversal of an N-ary Tree. Each group of children, from left to right, is separated by a null value. Each level is separated by a null value.
// In your levelOrder method implementation, you will print the nodes' values at each level with the level number.
// In our main method, we will directly call levelOrder method. We expect the output of your levelOrder to match the above format. 
// Note
// You do not need to implement a main function or the Node class. You are only required to implement the levelOrder function. We have created a main method that tests your levelOrder function.

// Sample Input:
// [12,null,1,4,5,null,null,7,11,null,8]
// Sample Output:
// Level: 1
// 12 
// Level: 2
// 1 4 5 
// Level: 3
// 7 11 8 

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

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root); 
    int level = 1; 
    int currentsize = 1;

    while (!q.empty()) {
        cout << "Level: " << level << endl;

        for (int i = 0; i < currentsize; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->val << " "; 

            for (int j = 0; j < current->children.size(); j++) {
                q.push(current->children[j]);
            }
        }
        
        currentsize = q.size();
        cout << endl; 
        level++; 
    }
}

