#include "AVL_Tree.h"
#include <iostream>
#include <iomanip>
using namespace std;

AVL_Tree::AVL_Tree()
{
    root = nullptr;
    nodeCount = 0;
}

int AVL_Tree::getNodeCount() const
{
    return nodeCount;
}

Node *AVL_Tree::getRoot() const
{
    return root;
}

void AVL_Tree::setRoot(Node *r)
{
    root = r;
}

Node *AVL_Tree::rotateLeft(Node *n)
{
    Node *temp = n->right;
    n->right = temp->left;
    temp->left = n;
    return temp;
}

Node *AVL_Tree::rotateRight(Node *n)
{
    Node *temp = n->left;
    n->left = temp->right;
    temp->right = n;
    return temp;
}

Node *AVL_Tree::rotateRightLeft(Node *n)
{
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}

Node *AVL_Tree::rotateLeftRight(Node *n)
{
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}

// recursively find height of tree
int AVL_Tree::height(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// balance factor = height of left subtree - right subtree
int AVL_Tree::balanceFactor(Node *root)
{
    if (root == nullptr)
        return 0;
    else
        return height(root->left) - height(root->right);
}

Node *AVL_Tree::insert(Node *root, string name, int ID)
{
    // AVL tree insertion logic
    if (root == nullptr)
    {
        cout << "successful" << endl;
        nodeCount++;
        return new Node(name, ID);
    }

    if (ID == root->gatorID)
    {
        cout << "unsuccessful" << endl;
        return root;
    }

    if (root->gatorID > ID)
        root->left = insert(root->left, name, ID);
    else
        root->right = insert(root->right, name, ID);

    // Update balance factor
    root->balanceFactor = balanceFactor(root);

    // Left heavy
    if (root->balanceFactor > 1)
    {
        // Left Right Case
        if (ID > root->left->gatorID)
            root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right heavy
    if (root->balanceFactor < -1)
    {
        // Right Left Case
        if (ID < root->right->gatorID)
            root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVL_Tree::printNodes(const vector<Node *> &nodes)
{
    for (unsigned int i = 0, end = nodes.size(); i < end; ++i)
    {
        cout << nodes[i]->studentName;
        if (i != end - 1)
            cout << ", ";
    }
}

void AVL_Tree::printLevelCount(Node *root)
{
    cout << height(root) << endl;
}

// traversals
void AVL_Tree::inOrder(Node *root, vector<Node *> &nodes)
{
    if (root == nullptr)
        return;

    inOrder(root->left, nodes);
    nodes.push_back(root);
    inOrder(root->right, nodes);
}

void AVL_Tree::printInorder(Node *root)
{
    vector<Node *> nodes;
    inOrder(root, nodes);
    printNodes(nodes);
}

void AVL_Tree::preOrder(Node *root, vector<Node *> &nodes)
{
    if (root == nullptr)
        return;

    nodes.push_back(root);
    preOrder(root->left, nodes);
    preOrder(root->right, nodes);
}

void AVL_Tree::printPreorder(Node *root)
{
    vector<Node *> nodes;
    preOrder(root, nodes);
    printNodes(nodes);
}

void AVL_Tree::postOrder(Node *root, vector<Node *> &nodes)
{
    if (root == nullptr)
        return;

    postOrder(root->left, nodes);
    postOrder(root->right, nodes);
    nodes.push_back(root);
}

void AVL_Tree::printPostorder(Node *root)
{
    vector<Node *> nodes;
    postOrder(root, nodes);
    printNodes(nodes);
}

bool AVL_Tree::searchID(Node *root, int ID)
{
    if (root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return false;
    }

    if (root->gatorID == ID)
    {
        cout << root->studentName << endl;
        return true;
    }

    if (ID > root->gatorID)
        return searchID(root->right, ID);
    return searchID(root->left, ID);
}

bool AVL_Tree::searchName(Node *root, string name)
{
    vector<Node *> nameMatch;
    vector<Node *> nodes;
    preOrder(root, nodes);

    for (Node *node : nodes)
    {
        if (node->studentName == name)
        {
            nameMatch.push_back(node);
            if (node->gatorID < 10000000)
            {
                cout << setw(8) << setfill('0') << node->gatorID << endl;
            }
            else
            {
                cout << node->gatorID << endl;
            }
        }
    }

    if (nameMatch.empty())
    {
        cout << "unsuccessful" << endl;
        return false;
    }
    return true;
}

// remove node with specified ID, return new root
Node *AVL_Tree::remove(Node *root, int ID)
{
    if (root == nullptr)
        return root;

    // ID is greater, so continue right subtree
    if (ID > root->gatorID)
    {
        root->right = remove(root->right, ID);
    }
    // ID is less, left subtree
    else if (ID < root->gatorID)
    {
        root->left = remove(root->left, ID);
    }
    else // Found the node to remove
    {
        nodeCount--;
        // Node with only right child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // Node with only left child or no child
        if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Find the inorder successor (node w the smallest value in right subtree)
        Node *temp = root->right;
        while (temp && temp->left)
            temp = temp->left;

        // Copy inorder successor's values to root
        root->gatorID = temp->gatorID;
        root->studentName = temp->studentName;
        root->right = remove(root->right, root->gatorID);
    }
    return root;
}

// remove node at specified order, return new root
Node *AVL_Tree::removeInorder(Node *root, int count)
{
    vector<Node *> nodes;
    inOrder(root, nodes);

    if (count > static_cast<int>(nodes.size()) - 1 || count < 0)
    {
        cout << "unsuccessful" << endl;
        return root;
    }

    root = remove(root, nodes[count]->gatorID);
    cout << "successful" << endl;
    return root;
}