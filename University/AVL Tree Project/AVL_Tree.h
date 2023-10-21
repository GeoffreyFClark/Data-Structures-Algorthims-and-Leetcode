#pragma once
#include "Node.h"
#include <vector>

class AVL_Tree
{
protected:
    int nodeCount;
    Node *root;

public:
    AVL_Tree();
    int getNodeCount() const;
    Node *getRoot() const;
    void setRoot(Node *r);

    Node *rotateLeft(Node *n);
    Node *rotateRight(Node *n);
    Node *rotateRightLeft(Node *n);
    Node *rotateLeftRight(Node *n);
    int height(Node *root);
    int balanceFactor(Node *root);
    Node *insert(Node *root, std::string name, int ID);
    void printNodes(const std::vector<Node *> &nodes);
    void printLevelCount(Node *root);
    void inOrder(Node *root, std::vector<Node *> &nodes);
    void printInorder(Node *root);
    void preOrder(Node *root, std::vector<Node *> &nodes);
    void printPreorder(Node *root);
    void postOrder(Node *root, std::vector<Node *> &nodes);
    void printPostorder(Node *root);
    bool searchID(Node *root, int ID);
    bool searchName(Node *root, std::string name);
    Node *remove(Node *root, int ID);
    Node *removeInorder(Node *root, int count);
};
