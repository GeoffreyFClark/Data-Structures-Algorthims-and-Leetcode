// The Minimum Number of Parentheses To Make the String Valid

// Problem Statement
// Given a string of ( and ) parentheses, write a method to find the minimum number of parentheses to add to make the string valid.

// Note
// An empty string is a valid parentheses string
// (S) is a valid parentheses string where S is a valid parentheses string
// )S( is not a valid parentheses string where S is a valid parentheses string
// ST is a valid parentheses string, where S and T are valid parentheses string
// The parentheses string only contains ( and ) characters.

// Input 1:
// ((
// Output 1:
// 2

//  Input 2:
// ())((
// Output 2:
// 3

// Sample Input:
// ((
// Sample Output:
// 2

#include <iostream>
#include <string>

int minParenToAdd(const std::string& s) {
    int openCount = 0;  // Count of '(' parentheses
    int closeCount = 0; // Count of unmatched ')' parentheses minus matched ones  

    for (char c : s) {
        if (c == '(') {
            openCount++;
        } else if (c == ')') {
            if (openCount > 0) {
                openCount--; // matching '(' followed by subsequent ')' cancel out
            } else {
                closeCount++; // No matching open parenthesis, add to count
            }
        }
    }

    return openCount + closeCount;
}