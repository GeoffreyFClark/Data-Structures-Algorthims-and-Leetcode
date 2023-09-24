// Binary Search Tree Insertion

// Problem Statement
// Given the root node to a Binary Search Tree, and a key, write a function that inserts the key at the appropriate position in the BST and returns the root node.

// The function will have the following signature:
// TreeNode* insert(TreeNode* root, int key)

// We have defined the following node C++ Node class for you:
//  class TreeNode {
//  public:
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

// Test Cases
// In the test cases, the line for input has multiple nodes and we will be inserting each one of them in your tree using your implemented insert function.
// The output is the result of an inorder traversal of the binary search tree. You don't need to implement inorder ﻿as it has already been taken care of.

// Sample Input:
// 50 30 20 40 70 60 80

// Sample Output:
// 20 30 40 50 60 70 80

#include <iostream>
using namespace std;

 class TreeNode {
 public:
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* insert(TreeNode* root, int key) {
    // base case - if root is nullptr
    if (root == nullptr) {
        return new TreeNode(key);
    }

    TreeNode *current = root;

    // traverse BST to find the appropriate position for the key
    while (current != nullptr) {
        if (key > current->val) {
            if (current->right == nullptr) {
                current->right = new TreeNode(key);
                break;
            } else {
                current = current->right;
            }
        } 
        else if (key < current->val) {
            if (current->left == nullptr) {
                current->left = new TreeNode(key);
                break;
            } else {
                current = current->left;
            }
        }
    }

    return root;
}