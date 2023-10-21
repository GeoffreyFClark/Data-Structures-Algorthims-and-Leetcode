#pragma once
#include <string>

struct Node
{
    std::string studentName;
    int gatorID;
    int balanceFactor;
    Node *left, *right;

    Node(std::string name, int id);
};
