#include "Handler.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool checkValidName(const string &name)
{
    // range based loop to check if each character is a digit
    for (char c : name)
    {
        if (!isalpha(c) && !isspace(c))
            return false;
    }
    return true;
}

bool checkValidID(const string &ID)
{
    if (ID.length() != 8)
        return false;

    for (char c : ID)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

// call appropriate function based on given command
void callHandler(string command, AVL_Tree &gatorAVL)
{
    size_t index = command.find(' ');
    string function = command.substr(0, index);
    command.erase(0, index + 1);

    if (function == "insert")
    {
        string name = command.substr(1, command.find('"', 1) - 1);
        string check = command.substr(name.length() + 3);

        if (checkValidID(check) && checkValidName(name))
        {
            int ID = stoi(check);
            gatorAVL.setRoot(gatorAVL.insert(gatorAVL.getRoot(), name, ID));
        }
        else
        {
            cout << "unsuccessful" << endl;
        }
    }
    else if (function == "remove")
    {
        if (checkValidID(command))
        {
            int ID = stoi(command);

            // check for ID existence:
            Node *current = gatorAVL.getRoot();
            bool exists = false;
            while (current != nullptr)
            {
                if (current->gatorID == ID)
                {
                    exists = true;
                    break;
                }
                else if (current->gatorID > ID)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            if (exists)
            {
                cout << "successful" << endl;
                gatorAVL.setRoot(gatorAVL.remove(gatorAVL.getRoot(), ID));
            }
            else
            {
                cout << "unsuccessful" << endl;
            }
        }
        else
            cout << "unsuccessful" << endl;
    }
    else if (function == "search")
    {
        if (command[0] == '"')
        {
            string name = command.substr(1, command.length() - 2);
            if (checkValidName(name))
                gatorAVL.searchName(gatorAVL.getRoot(), name);
            else
                cout << "unsuccessful" << endl;
        }
        else
        {
            if (checkValidID(command))
                gatorAVL.searchID(gatorAVL.getRoot(), stoi(command));
            else
                cout << "unsuccessful" << endl;
        }
    }
    else if (function == "printInorder")
    {
        gatorAVL.printInorder(gatorAVL.getRoot());
        cout << endl;
    }
    else if (function == "printPreorder")
    {
        gatorAVL.printPreorder(gatorAVL.getRoot());
        cout << endl;
    }
    else if (function == "printPostorder")
    {
        gatorAVL.printPostorder(gatorAVL.getRoot());
        cout << endl;
    }
    else if (function == "printLevelCount")
    {
        gatorAVL.printLevelCount(gatorAVL.getRoot());
    }
    else if (function == "removeInorder")
    {
        try
        {
            int order = stoi(command);
            gatorAVL.setRoot(gatorAVL.removeInorder(gatorAVL.getRoot(), order));
        }
        catch (const std::exception &)
        {
            cout << "unsuccessful" << endl;
        }
    }
}