// Balancing a Binary Search Tree

// Problem Statement
// Write three rotation functions:
// Node* rotateLeft(Node *node); 
// Node* rotateRight(Node *node); 
// Node* rotateLeftRight(Node *node); 
// These functions can be used to transform an unbalanced Binary Tree to a balanced Binary Tree. 

// These functions will do the following:
// 1. Take a node named node.
// 2. Perform the respective rotations for the unbalanced tree: left, right, and left right.
// 3. Return the new root. 

// The left right rotation should be performed as a left rotation on node's left child, then a right rotation on node.
// You do not need to worry about building the binary tree as we have already implemented insert behind the scenes.
// The node, given to you in the functions' parameter, will be an already constructed Binary Search Tree (BST) made from the input values.

// We have defined the following C++ Node class for you:
// class Node 
// {
//     public: 
//        std::string name; // The name serves as the node's value.
//        Node* left = NULL;
//        Node* right = NULL;
// };

// This diagram illustrates how a tree should look after a left or right rotation: 

//           C                    B                    A
//          / \                 /   \                 / \
//         B   Z               A     C               W   B
//        / \       right     / \   / \      left       / \
//       A   Y     ------>   W   X Y   Z   <------     X   C
//      / \                                               / \
//     W   X                                             Y   Z

// Test Cases
// The input is constructed as follows:
// Line 1 - The number of nodes in the BST.
// Line 2 - The nodes of the BST inserted as in the given order.

// How we will test your code:
// 1. We will create the BST for you by inserting each node one at a time from the input.
// 2. Call rotateLeftRight on the root of the tree.
// 3. Do pre-order, in-order, and post-order traversals.
// 4. The output is a single string of pre-order, then in-order, and lastly post order traversals of the rotated BST concatenated and separated by spaces.
// Note - You do not have to build the BST or do the traversals, just build the rotation functions specified.

// Sample Input:
// 3
// 2 0 1

// Sample Output:
// 102 012 021

Node* rotateLeft(Node *node)
{
    Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

Node* rotateRight(Node *node)
{
    Node *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

Node* rotateLeftRight(Node *node)
{
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}