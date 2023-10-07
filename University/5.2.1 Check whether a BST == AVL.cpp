// BST = AVL ?

// Problem Statement
// AVL Tree is a Binary Search Tree that allows Balance Factor of each node to be in the range -1 to 1 (n>=0). Implement a function that takes as input a root node of a Binary Search Tree. This function checks if the BST is an AVL Tree or not.

// We have defined the following C++ Node class for you:
// class Node
// {
//     public:
//         int name;
//         Node* left = NULL;
//         Node* right = NULL;
// };
// Function to code
// bool isAVL(Node* root);
 
// Example:
// Inserted Numbers in a BST: -  5 2 15 16 9 11 14 ;
// Tree:-           5

//              /        \

//            2           15

//                   /         \

//                 9            16

//                     \

//                       11

//                          \

//                             14

// Balance Factor of tree = left subtree height – right subtree height = -3
// Therefore, this BST is not an AVL Tree.

 

// Test Cases
// The input in test cases are nodes of a tree which are inserted in that order. 
// You don't need to implement insert. 
// You have access to the root of the constructed Binary Search Tree. 
// Return true if the BST is a valid AVL Tree and False if not.

// Hint: Use a Height function to calculate height of a tree at given node.

// Sample Input:
// 5 2 15 16 9 11 14 

// Sample Output:
// false

int treeHeight(Node* node, bool &isBalanced)
{
    if (node == nullptr)
        return 0;

    int leftHeight = treeHeight(node->left, isBalanced);
    int rightHeight = treeHeight(node->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;
    
    return 1 + std::max(leftHeight, rightHeight);
}

bool isAVL(Node* root)
{
    bool isBalanced = true;
    treeHeight(root, isBalanced);
    return isBalanced;
}
