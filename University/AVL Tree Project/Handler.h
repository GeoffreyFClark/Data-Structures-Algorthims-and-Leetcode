#pragma once
#include "AVL_Tree.h"
#include <string>

bool checkValidName(const std::string &name);
bool checkValidID(const std::string &ID);
void callHandler(std::string command, AVL_Tree &gatorAVL);
