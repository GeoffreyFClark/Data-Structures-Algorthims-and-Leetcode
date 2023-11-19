// Dijkstra's Shortest Paths From Source Vertex to all Vertices

// Problem Statement
// Given a directed graph and a source vertex, write a method to find 
// shortest paths from a source vertex to all other vertices in the graph.

// The function will have the following signature:
// vector<int> dijkstra(const Graph& graph, int src)


// We have defined the following Graph class and Edge struct for you:

// struct Edge {
// 	int src, dest, weight;
// 	Edge(int _src, int _dest, int _weight) {src = _src; dest = _dest; weight = _weight;}
// };

// class Graph {
// public:
// 	int numVertices;
// 	vector<vector<pair<int, int>>> adjList; 
//     // e.g. 0: {1, 12}, {2, 4} -> the weight from vertex 0 to 1 is 12 
//     //                        and the weight from vertex 0 to 2 is 4

// 	Graph(const vector<Edge>& edges, int vertices) {
// 		numVertices = vertices;

// 		adjList.resize(vertices);

// 		for (auto &edge : edges) {
// 			adjList[edge.src].push_back(make_pair(edge.dest, edge.weight));
// 		}
// 	}
// };


// Examples
// Input: 
// 7 0
// [[0,1,4],[1,2,1],[2,3,8],[3,4,9],[3,5,5],[5,4,12],[6,5,7],[0,6,10],[1,6,2],[6,2,6]]

// Output: 
// Vertex Distance from Source:
// 0	0
// 1	4
// 2	5
// 3	13
// 4	22
// 5	13
// 6	6

// Test Cases
// As for the input first line, the first item is the number of vertices in the graph. 
// The second item is the source vertex.
// The second line of input is a list of edges in the graph.
// The output indicates the shortest path from the source vertex to all vertices in the graph.

// Note
// You are only required to return a vector<int>  that contains the 
// shortest path from the source vertex to all vertices in the directed graph.
// You should not print anything out in the dijkstra method. 
// We will print out the items you return in the main method.

// Sample Input:
// 7 0
// [[0,1,4],[1,2,1],[2,3,8],[3,4,9],[3,5,5],[5,4,12],[6,5,7],[0,6,10],[1,6,2],[6,2,6]]

// Sample Output:
// Vertex Distance from Source:
// 0	0
// 1	4
// 2	5
// 3	13
// 4	22
// 5	13
// 6	6



#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(const Graph& graph, int src) {
    // Initialize distances to a large value (infinity equivalent)
    vector<int> dist(graph.numVertices, 1e7);

    // Min-priority queue to pick the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Set distance to the source vertex as 0 and add it to the priority queue
    dist[src] = 0;
    pq.push(make_pair(0, src));

    // Main loop
    while (!pq.empty()) {
        // Extract the vertex with the smallest distance from the queue
        int u = pq.top().second;
        pq.pop();

        // Iiterate over all adjacent vertices
        for (const auto &i : graph.adjList[u]) {
            int v = i.first; // Destination vertex
            int weight = i.second; // Weight of edge

            // If a shorter path to v is found
            if (dist[v] > dist[u] + weight) {
                // Update the distance of vertex v
                dist[v] = dist[u] + weight;
                // Add the updated distance to the priority queue
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Return the computed shortest distances
    return dist;
}
