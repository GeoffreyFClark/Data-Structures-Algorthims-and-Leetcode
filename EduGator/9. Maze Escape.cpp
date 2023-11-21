// Maze Escape

// Problem Statement
// Sometimes when dealing with graphs, it is easiest to leave it in its input format rather than creating another structure like an adjacency list/matrix. 
// You are given a graph represented as a vector of strings. 
// Write a function traverse(vector<string>& graph) that takes as input a graph and returns the length of the shortest path between vertices s and t. 
// If no path exists between s and t, then return -1. The details of the graph as a vector of strings are as follows:

// The start position is represented by a 's' and will always be the first character of the first string (graph[0][0]).
// The end position is represented by a 't' and will always be the last character of the final string (graph[graph.size()-1][graph[0].length()-1]).
// A '.' character represents a normal vertex in the graph.
// A '#' character represents that you cannot visit this vertex in the graph (or there is no vertex at this position).
// Adjacent vertices are those immediately horizontal or vertical from the current vertex (diagonal moves are not allowed).
// The cost of moving along one edge (from one vertex to an adjacent vertex) is always 1 (i.e. this is an unweighted graph).

// Sample Input
// s#.#.
// .#...
// ...#t

// Sample Output
// 8

// Explanation
// The shortest path from 's' to 't' involves 8 steps between adjacent vertices (including the initial step from 's' and the final step to 't').

// Constraints
// 0 < graph.size() <= 100
// 0 < graph[0].length() <= 100
// graph[i].length() is the same for all 0 <= i < graph.size()

#include <iostream>
#include <vector>
#include <queue>

int traverse(std::vector<std::string>& graph) {
    int rows = graph.size();
    int cols = graph[0].length();

    // Define possible moves: up, down, left, right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Find the starting position 's'
    int startR, startC;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (graph[i][j] == 's') {
                startR = i;
                startC = j;
                break;
            }
        }
    }

    // 2D array to keep track of visited vertices
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    // queue for BFS
    std::queue<std::pair<int, int>> q;

    // Push the starting position into the queue
    q.push({startR, startC});
    visited[startR][startC] = true;

    // Initialize the distance as 0
    int distance = 0;

    // BFS
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check if we've reached the target 't'
            if (graph[r][c] == 't') {
                return distance;
            }

            // Explore adjacent vertices
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check if the adjacent cell is within bounds and is a valid vertex
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && graph[nr][nc] != '#' && !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        distance++; // Increment the distance after processing each level
    }

    // If 't' is not reachable, return -1
    return -1;
}