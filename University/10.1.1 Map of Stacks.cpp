// Map of Names

// Problem Statement
// You are supposed to write two methods using the map data structure in C++.

// map <int, stack<string>> createMap(string[], int);
// bool isPresent(map <int, stack<string>>, string);


// Method 1
// The first method takes an array of strings and the length of that array and creates a map with the key - String Length and value - String Name. 
// The latter values are pushed into a Stack of strings where each stack stores all strings of the same length. 
// This method returns the map created with all lengths as keys and all strings in stacks of the respective keys. 
// You have to use the Stack implementation of Standard Template Library.

// Example:
// Input - ["Hello",  "Aman",  "World"] ,  3
// Output - [ {4: ("Aman") },  {5: ("Hello", "World") } ]

 
// Method 2
// The second method takes a map and a string and checks if the given string is present in the map you created.

// Example:
// Input - [ {4: ("Aman") },  {5: ("Hello", "World") }, "Hello"]
// Output- 1 (true)

// Test Cases
// Line 1 of input represents the number of strings in the map.
// Line 2 of input represents the strings that will be inserted in the map separated by spaces.
// Line 3 of input represents the string we will be searching in the map.
// Output is a the result of the call to the isPresent() function. We will call your function with a random string. The 

// Sample Input:
// 7
// Apple Microsoft Google Facebook Netflix Rat Maple
// Rat

// Sample Output:
// 1


map<int, stack<string>> createMap(string arr[], int len) {
    map<int, stack<string>> mapOfStacks;
    for (int i = 0; i < len; i++) { 
        string& x = arr[i];
        mapOfStacks[x.length()].push(x);
    }
    return mapOfStacks;
}

bool isPresent(map<int, stack<string>> obj, string value) {
    auto iter = obj.find(value.length());
    if (iter != obj.end()){
        stack<string> tempStack = iter->second;
        while (!tempStack.empty()) {
            if (tempStack.top() == value) {
                return true;
            }
            tempStack.pop();
        }
    }
    return false;
}