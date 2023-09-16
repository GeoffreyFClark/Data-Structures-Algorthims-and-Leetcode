// STL Iterators for Lists

// Problem Statement
// Write the method int findInList(std::list<int> &myList, int valueToFind). 
// The method takes as arguments: a list and a value. 
// The method implementation must create an iterator and use the iterator to find the value in the list.  
// Return -1 if the item is not in the list.

// Recommended Readings
// http://www.cplusplus.com/reference/iterator/
// https://www.geeksforgeeks.org/iterators-c-stl/

// Test cases
// We have implemented the main( ) for you. The main calls your findInList( ) method.

// Input: 
// Line 1 has two integers: Value 1 is the number of elements in the list and Value 2 is the value you need to find. 
// Line 2 is the Linked List passed into the findInList( ) method. 

// Output: 
// Index of the found value. -1 if the value not present in the list.

// Sample Input:
// 4 2
// 1 2 3 4

// Sample Output:
// 1

#include <iostream>
#include <string>
#include <list>

int findInList(std::list<int> &myList, int valueToFind) {
    int index = 0;
    for (auto iter = myList.begin(); iter != myList.end(); iter++) {
        if (valueToFind == *iter) {
            return index;
        }
        index++;
    }
    return -1;
}