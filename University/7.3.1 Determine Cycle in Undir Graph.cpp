// Detect whether there is a Cycle in an Undirected Graph

// Problem Statement
// Given an undirected graph, write a method to detect whether there is a cycle in it.

// The function will have the following signature:
// bool anyCycle(const Graph& graph)

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

// Example
// Input: 
// 8 
// [[0,1],[0,2],[1,2],[2,6],[1,3],[3,4],[3,5],[4,7]]
// Output: 
// Graph contains a cycle

// Test Cases
// The first line of the input indicates the number of vertices in the graph.
// Assume the vertices are from 0 to  number of vertices - 1.
// The second line of input is a list of edges in the graph. 
// For example, [2,6] means that there is an edge from vertex 2 to vertex 6 and an edge from vertex 6 to vertex 2.
// We will read in the edges and place them into an adjacency list.  

// Note
// We will call your anyCycle method directly in the main method.
// You just need to return true of false to indicate whether there is a cycle. 
// We will print out "Graph contains cycle" or "Graph doesn't contain cycle" in the main method based on the result of the function call.
// The graph can have disconnected vertices.

// Sample Input:
// 8
// [[0,1],[0,2],[1,2],[2,6],[1,3],[3,4],[3,5],[4,7]]
// Sample Output:
// Graph contains cycle



// Helper function
bool dfsCycleDetect(const Graph& graph, int v, vector<bool>& visited, int parent) {
    visited[v] = true;
    
    // Iterate recursively over all adjacent vertices
    for (int adj : graph.adjList[v]) {
        if (!visited[adj]) {
            if (dfsCycleDetect(graph, adj, visited, v))
                return true; 
        } else if (adj != parent) {
            // If adjacent vertex IS visited AND is NOT parent, cycle is found
            return true;
        }
    }
    return false;
}

bool anyCycle(const Graph& graph) {
    vector<bool> visited(graph.numVertices, false);

    // Iterate through all vertices of the graph
    for (int i = 0; i < graph.numVertices; i++) {
        // If vertex not visited, start depth first search
        if (!visited[i]) {
            if (dfsCycleDetect(graph, i, visited, -1))
                return true; // If a cycle is detected, return true
        }
    }
    return false;
}
