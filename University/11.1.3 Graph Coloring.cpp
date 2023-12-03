// Graph Coloring

// Problem Statement
// Graph coloring is a special, common, yet simply described problem- How can we assign a color to every node of a graph such that no two nodes which share an edge also share the same color? Here's an example using an undirected graph:

// ![image1](https://media.cheggcdn.com/media/66b/66b5b59e-a42d-4124-999e-87d3af65b507/phpnemFWf.png)
// Notice how no node has any neighbors with the same color as itself. 

// This problem is a good introduction to Greedy algorithms, which are algorithms that makes the best sounding decision at each step of solving the problem in hopes that the overall solution will be optimal in the end. Greedy algorithms are sometimes successful in finding the optimal solutions, but not always. For example, in this specific problem the greedy approach doesn't guarantee to use the minimum number of colors but it does provide an upper bound of no more colors than the maximum degree of a vertex in any graph- which is still pretty good for a relatively simple algorithm.

// The greedy algorithm for graph coloring is as follows:

// 1. Color the starting vertex with the first color
// 2. For the remaining vertices, color it with the a color that has been used before but is not the color of any adjacent vertex. If there are none, make a new color and assign it to that vertex.

// For this assignment, you will be asked to fill in the color method, which has a signature of std::vector<string> color(Graph& graph) which takes in a reference to a graph object, which is defined by the following snippet:

// class Graph {
// public:
// 	// An array of vectors to represent an adjacency list
// 	vector<vector<int>> adjList;

// 	// The number of vertices in the graph
// 	int V;

// 	// The Constructor
// 	Graph(...) {...}
// };

// The method will return a vector of strings, in upper case, denoting the color of the ith node in the order that was given in the Graph class's adjList member.
// The colors are ranked as such:
// 0 - RED
// 1 - BLUE
// 2 - GREEN
// 3 - YELLOW
// 4 - ORANGE
// 5 - PURPLE

// This means the first node should be assigned red, and you should be assigning the next node blue and so on. 

// Example
// Graphs will be inputted as a vector of edges, so for example take the following graph:
// ![image2](https://ucarecdn.com/a5fafcad-1a83-4ec2-bb53-8973a647ffc1/)
// It will be inputted as [[0,1], [0,4], [0,5], [4,5], [1,4], [1,3], [2,3], [2,4]] and the expected output is:

// Vertex 0: RED
// Vertex 1: BLUE
// Vertex 2: RED
// Vertex 3: GREEN
// Vertex 4: GREEN
// Vertex 5: BLUE

// This is visually as follows:
// ![image3](https://ucarecdn.com/4cc99696-5e95-4031-b690-2ac45f24575c/)

// And we are confident in our result as no two adjacent nodes share the same color.

// Constraints
// The graph is undirected and will always be connected
// 1 < V < floor(sqrt(INT_MAX))
// 1 < E < V(V-1)/2

// Sample Input:
// [[0,1],[0,4],[0,5],[4,5],[1,4],[1,3],[2,3],[2,4]]

// Sample Output:
// Vertex 0: RED
// Vertex 1: BLUE
// Vertex 2: RED
// Vertex 3: GREEN
// Vertex 4: GREEN
// Vertex 5: BLUE

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> color(Graph& graph) {
    vector<string> colors(graph.V, ""); // Vector to store color of each vertex
    vector<string> colorNames = {"RED", "BLUE", "GREEN", "YELLOW", "ORANGE", "PURPLE"};
    
    // Assign the first color to the first vertex
    colors[0] = colorNames[0];

    // Initialize all vertices as unassigned
    vector<bool> colorAvailable(colorNames.size(), true);

    // Assign colors to remaining vertices
    for (int u = 1; u < graph.V; u++) {
        // Process all adjacent vertices and flag their colors as unavailable
        for (int i : graph.adjList[u]) {
            if (colors[i] != "") {
                auto it = find(colorNames.begin(), colorNames.end(), colors[i]);
                if (it != colorNames.end()) {
                    colorAvailable[it - colorNames.begin()] = false;
                }
            }
        }

        // Find the first color that is available
        int cr;
        for (cr = 0; cr < colorNames.size(); cr++) {
            if (colorAvailable[cr]) break;
        }

        if (cr < colorNames.size()) {
            colors[u] = colorNames[cr]; // Assign the found color
        }

        // Reset the values back to true for the next iteration
        fill(colorAvailable.begin(), colorAvailable.end(), true);
    }

    // Return the result
    return colors;
}
