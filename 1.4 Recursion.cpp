// 1.4 Recursion

// 1.4.1 Factorial
// Write a function that finds the factorial of a number, N using recursion.
// Constraints
// 0 <= N < 21
// Sample Input: 5
// Sample Output: 120
#include <iostream>
long factorial(long num) {
    if (num > 1) {
        return num * factorial(num - 1);
    } else {
        return 1;
    }
}

//1.4.2 Palindrome
// Write a function that checks if a string is palindrome recursively.
// Sample Input: ABBBA
// Sample Output: true
bool checkPalindrome(string s) {
    if (s.length() <= 1) return true;
    if (s[0] == s[s.length()-1]) {
        return checkPalindrome(s.substr(1, s.length()-2));
    } else {
        return false;
    }
}
