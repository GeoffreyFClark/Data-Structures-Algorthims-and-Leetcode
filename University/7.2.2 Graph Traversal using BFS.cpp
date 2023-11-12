// Traversal of An Undirected Graph Using Breadth First Search (BFS)

// Problem Statement
// Given an undirected connected graph, write a methods to perform breadth first search (BFS) on it.

// The function will have the following signature:
// bool bfs(const Graph& graph, int src)

// We have defined the following Graph class and Edge struct for you:

// struct Edge {
// 	int src, dest;
// 	Edge(int _src, int _dest) {src = _src; dest = _dest;}
// };

// class Graph {
// public:
// 	int numVertices;
// 	vector<vector<int>> adjList;

// 	Graph(const vector<Edge>& edges, int vertices) {
// 		numVertices = vertices;

// 		adjList.resize(vertices);

// 		for (auto &edge : edges) {
// 			adjList[edge.src].push_back(edge.dest);
// 			adjList[edge.dest].push_back(edge.src);
// 		}
// 	}
// };

// Examples

// Input: 
// 8 0 
// [[0,1],[0,2],[1,2],[2,6],[1,3],[3,4],[3,5],[4,7]]
// Output: 
// 0 1 2 3 6 4 5 7

// Input: 
// 8 2
// [[0,1],[0,2],[1,2],[2,6],[1,3],[3,4],[3,5],[4,7]]
// Output:
// 2 0 1 6 3 4 5 7 

// Test Cases
// The first line of the input indicates the number of vertices in the graph, followed by a source vertex. 
// The second line of input is a list of edges in the graph. 
// For example, [2,6] means that there is an edge from vertex 2 to vertex 6 and an edge from vertex 6 to vertex 2.
// We will read in the edges and place them into an adjacency list.  
// We will then call a breadth first search method that you will implement.  
// Your method should print out the list of vertices in a breadth first order.

// Note
// Breadth first search is not unique.  We need unique answers so we can test.  So for this implementation, all ties are broken by choosing the vertex whose ID has the lowest numerical value.
// You are required to print out the list of vertices in breadth first search order in the bfs method.
// We will call your bfs method directly in the main method.

// Sample Input:
// 8 0
// [[0,1],[0,2],[1,2],[2,6],[1,3],[3,4],[3,5],[4,7]]
// Sample Output:
// 0 1 2 3 6 4 5 7 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(const Graph& graph, int src) {
    vector<bool> visited(graph.numVertices, false);
    queue<int> q;
    vector<int> result;

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        vector<int> neighbors = graph.adjList[current];
        sort(neighbors.begin(), neighbors.end()); // Sort neighbors for tie-breaking per test cases

        // Visit neighbors in sorted order
        for (int i = 0; i < neighbors.size(); ++i) {
            int neighbor = neighbors[i];
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    // Print result in BFS order
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}
