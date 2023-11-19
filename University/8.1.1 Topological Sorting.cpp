// Topological Sorting in Course Scheduling System

// Problem Statement
// Given the total number of courses as numCourses and a list of prerequisites pairs as req, 
// implement finishCourses method to determine whether the students could finish 
// all the courses based on the current course scheduling system.

// As for the pair in the prerequisites list, 
// e.g. [2, 1] means that students have to take course 2 before taking course 1. 

// Example:
// Input: numCourses = 3, req = [[1, 0], [0, 2]]
// Output: true

// Explanation
// There are a total of 3 courses to take. This information is denoted by numCourses
// [1,0] means before taking course 0, students have to take course 1. 
// [0, 2] means before taking course 2, students have to take course 0
// In this example, students could first take course 1, then course 0 followed by course 2. 
// Thus, it is possible for students to finish all the courses and we output true.

// Test Cases
// The input req is a graph represented by a list of edges.
// There are no duplicate or parallel edges in the input req.

// Note
// You are required to return true of false based on the current course prerequisites list. 
// You don't need to print out anything in your finishCourses method implementation. 

// Sample Input:
// 3
// [[1,0],[0,2]]

// Sample Output:
// true

#include <vector>
#include <queue>
using namespace std;

bool finishCourses(int numCourses, vector<vector<int>>& req) {
    // Create a graph and an array to track the number of prerequisites (in-degrees) for each course
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);

    // Iterate over the prerequisites, building the graph and incrementing in-degrees
    for (const auto& p : req) {
        graph[p[1]].push_back(p[0]); // Add edge from prerequisite to the course
        inDegree[p[0]]++; // Increment in-degree for the course
    }

    // Initialize a queue to perform topological sort
    queue<int> q;
    // Enqueue courses with no prerequisites
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Variable to count the number of courses processed
    int count = 0;
    // Process courses in topological order
    while (!q.empty()) {
        int current = q.front(); // Get the current course with no prerequisites
        q.pop();
        count++; // Increment count as one more course is processed

        // Decrease in-degree for all adjacent courses and enqueue if in-degree becomes zero
        for (int neighbor : graph[current]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check if all courses have been processed
    return count == numCourses;
}
