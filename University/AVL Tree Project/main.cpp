#include "Handler.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    AVL_Tree gatorAVL;
    int numCommands;
    cin >> numCommands;
    string line;
    vector<string> commandqueue;

    for (int i = 0; i < numCommands + 1; i++)
    {
        getline(cin, line);
        commandqueue.push_back(line);
    }

    for (unsigned int i = 0; i < commandqueue.size(); i++)
    {
        string command = commandqueue[i];
        callHandler(command, gatorAVL);
    }

    return 0;
}
