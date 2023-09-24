// Binary Search Tree Leaf Nodes

// Problem Statement
// Given the root node to a Binary Search Tree, write a function to print the leaf elements of the BST, starting from right to left.
// The function will have the following signature:

// void printLeaves(TreeNode* root);
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

// Examples:-

// 1. Numbers: -  5 2 15 16 9 11 14
// Tree:-           5

//                  /        \

//                2          15

//                          /         \

//                       9            16

//                           \

//                             11

//                                  \

//                                    14
// Output: -  16 14 2

// 2. Numbers: -  5 2 15
// Tree:-           5

//                  /        \

//                2          15
// Output: - 15 2

// Test Cases
// The first input in test cases are nodes of a tree which are inserted in that order. You don't need to implement insert.
// You have access to the root of the constructed Binary Search Tree.
// The output are the leaves separated by one space " " printed from right to left.

// Sample Input:
// 5 2 15 16 9 11 14

// Sample Output:
// 16 14 2

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

void printLeaves(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    if (root->left == nullptr && root->right == nullptr)
        std::cout << root->val << " ";
    
    printLeaves(root->right);
    printLeaves(root->left);
}
