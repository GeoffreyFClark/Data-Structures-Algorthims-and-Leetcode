// Flip a binary tree over its center vertical axis

// Problem Statement
// Given the root to a binary tree, write a method to flip the tree across the vertical axis. The method will have the following signature:
// void Flip(TreeNode* root)

// The following TreeNode class has already been defined for you:
// class TreeNode {
//      public:
//           int val;
//           TreeNode *left;
//           TreeNode *right;
//           TreeNode() : val(0), left(nullptr), right(nullptr) {}
//           TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// Constraints
// The tree is not guaranteed to be full, balanced, or complete.
// The tree consists of strictly positive integers
// An empty tree will not be passed in
// The tree is binary in nature and will be passed in through input as a level order traversal, e.g the tree
//     1
//    / \
//   2   3
//  /   / \
// 4    6  7
// will be entered into input as [1, 2, 3, 4, null, 6, 7]. null represents no node present in the level order at the corresponding location.

// Explanation
// You will be given a root node to a tree, which, as an example, looks like this:

//     1
//    / \
//   2   3
//  / \ / \
// 4  5 6  7    
// After calling flip on the root node, the tree should be flipped across its center vertical axis represented by the dash line:

//     |
//     1
//    /|\
//   2 | 3
//  / \|/ \
// 4  5|6  7
//     |    
// Resulting in our final tree looking like:

//     1
//    / \
//   3   2
//  / \ / \
// 7  6 5  4    

// Sample Input:
// [1,2,3,4,5,6,7]

// Sample Output:
// [1,3,2,7,6,5,4]

