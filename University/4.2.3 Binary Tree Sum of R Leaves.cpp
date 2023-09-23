// Binary Tree Sum of Right Leaves

// Problem Statement
// Given the root node of a binary tree, write a method to print the sum of all right leaves of the binary tree. 
// The method will have the following signature:
// void sumOfRightLeaves(TreeNode* root)

// The following TreeNode class has already been defined for you:
// class TreeNode {
//  public:
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
// Example 1:
// Input: [3,9,20,null,12,15,7]
// Output: 19

// Example 2: 
// Input: [2,1,3,null,null,null,9,null,8]
// Output: 8
 
// Test Cases
// Input of Binary Tree is represented in their level order traversal. 
// null represents no node present in the level order at the corresponding location.
// In your sumRightLeaves method, you need to print out the sum of all the values of right leaves.
// In our main method, we will directly call sumRightLeaves method. 

// Note
// You just need to complete the sumRightLeaves method implementation. We will be testing your code and implementing the main( ) function. 

// Sample Input:
// [3,9,20,null,12,15,7]

// Sample Output:
// 19

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
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

int sumRightLeavesHelper(TreeNode* node) {
    if (!node) {
        return 0;
    }

    int sum = 0;

    // Check if right child is a leaf node
    if (node->right && !node->right->left && !node->right->right) {
        sum += node->right->val;
    }

    sum += sumRightLeavesHelper(node->left);
    sum += sumRightLeavesHelper(node->right);

    return sum;
}

void sumOfRightLeaves(TreeNode* root) {
    int answer = sumRightLeavesHelper(root);
    cout << answer << endl;
}