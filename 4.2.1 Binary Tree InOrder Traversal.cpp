// Binary Tree Inorder Traversal

// Problem Statement
// Write a function traverse(TreeNode* root) that takes as input the root node of a tree 
// and returns a string with an in order tree traversal.

// The following TreeNode class has already been defined for you:
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
// Input of Binary Tree is represented in their level order traversal. null represents no node present in the level order at the corresponding location.
// Output of the traverse method is a string with an in order tree traversal.

// Note
// You just need to complete the traverse method implementation. We will be testing your code and implementing the main( ) function. 

// Sample Input:
// [4,2,3,0,1]

// Sample Output:
// 02143

#include <vector>
#include <sstream>
#include <queue>
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

string traverse(TreeNode* root){
    if (root == nullptr) {
        return "";
    }
    return (
        traverse(root->left) + 
        to_string(root->val) + 
        traverse(root->right)
    );
}