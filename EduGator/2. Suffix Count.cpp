// Problem Statement
// In this problem, you will write a function that returns the count of a string’s suffix in a given string, S. A suffix is a combination of one or more symbols appended at the end of the string. You will be given the length, L of the suffix as a parameter to the function.

// Constraints
// S does not contain new line characters
// Length (S) >= L > 0

// Sample Input
// et tu, brute
// 1

// Sample Output
// 2

// Explanation
// Input: Line 1 denotes the string with no newline characters and Line 2 denotes the length, L of the suffix
// Output: The suffix is ‘e’ and ‘e’ is present twice in string S, “et tu, brute”. Therefore, the count will be 2.

#include <iostream>
#include <string>
using namespace std;

int suffixCount(string S, int L) {
    string suffix = S.substr(S.length() - L, L);
    int count = 0;
    for (int i = 0; i <= S.length() - L; i++) {
        if (S.substr(i, L) == suffix) {
            count++;
        }
    } 
    return count;
}
