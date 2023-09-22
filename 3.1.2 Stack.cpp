// Problem Statement
// Write a method bool inLanguage(char* theString) that uses one stack to determine 
// whether theString has the same number of A's as B's.  
// If the string contains anything other than A or B (capital A or capital B), return false.

#include <iostream>
#include <string>
#include <stack>

bool inLanguage(char* theString) {
    int index = 0;
    std::stack<char> charstack;
    char currentChar = theString[index];
    
    while(currentChar != '\0') {
        if(currentChar != 'A' && currentChar != 'B') {
            return false;
        } else if (charstack.empty() || charstack.top() == currentChar) {
            charstack.push(currentChar);
        } else {
            charstack.pop();
        }
        currentChar = theString[++index];
    }
    return charstack.empty();
}