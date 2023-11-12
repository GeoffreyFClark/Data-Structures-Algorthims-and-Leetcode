// Graph Implementation using an Adjacency List

// Problem Statement
// In this problem, you are expected to implement a directed graph using adjacency list representation. 
// The graph must support the following operations:

// class Graph
// {
//     private:
//       //Graph as an adjacency list - data member, e.g. Vector, Set, Vector of Vectors, Maps, Lists, etc.
//       //It is encouraged you have two data members: to keep a track of vertices and to keep track of Graph

//    public:
//       void insertEdge(int from, int to, int weight);  
//       bool isEdge(int from, int to);
//       int getWeight(int from, int to);
//       vector<int> getAdjacent(int vertex);  
//     void printGraph(); 

// };

// Explanation
// insertEdge() adds a new edge between the from and to vertex. You will not know how many vertices there may be.
// isEdge() returns a boolean indicating true if there is an edge between the from and to vertex
// getWeight() returns the weight of the edge between the from and to vertex
// getAdjacent() returns a sorted vector of all vertices that are connected to a vertex
// printGraph() prints the graph in a format sorted by ascending vertex and ascending edge list

// Test cases
// You are expected to write code for each of the functions as well as implement the graph.
// Do not assume that the vertex values will be sequential (e.g. vertex values can be 2, 25, 54, and 74).
// Remember to account for invalid inputs when you solve this! (As in, a certain vertex doesn't exist).
// A sample int main() function that invokes your graph is provided. Make sure you do not change any code in the main() function.

// Input: 
// Line 1 indicates the number of operations you will be performing or the number of lines that follow.
// For the next n lines, each line's first digit is an integer stating which function is invoked. This is followed by the appropriate parameters passed into the function signature.
// 1 refers to a call to insertEdge()
// 2 refers to a call to isEdge() 
// 3 refers to a call to getWeight() 
// 4 refers to a call to getAdjacent() 
// 5 refers to a call to printGraph() 
// Output: 
// We print the graph by either calling option 5 or by explicitly printing the returned vector in option 4.

// Input:
// 5                    - Line 1 indicates the number of operations you will be performing or the number of lines that follow
// 1 5 6 50        - 1 is insertEdge. "From" is 5 and "To" is 6. The edge has a weight of 50 Therefore, operation is insertEdge(5,6,50)
// 2 6 5              - 2 is isEdge.  Therefore, operation is isEdge(6,5)
// 3 5 6              - 3 is getWeight. Therefore, operation is getWeight(5,6)
// 4 5                 - 4 is getAdjacent. Therefore, operation is getAdjacent(5)
// 5                    - 5 is printGraph. Therefore, operation is printGraph()
// Output:
//               -  insertEdge does not output or print anything
// 0           -   isEdge (6,5) returns false
// 50         -  getWeight (5,6) returns 50
// 6           -  getAdjacent(5) returns adjacent vertices in sorted order based on name.
// 5 6        -  printGraph() prints the graph in the format: Vertex EdgeList in ascending order of vertices and their respective edge lists
// 6           -  This graph has 2 vertices 5, 6. So print vertex (1 per line) and in that line print the edges it is connected to in sorted order

// Sample Input:
// 6
// 1 1 2 3
// 1 2 3 7
// 1 2 4 5
// 1 3 4 15
// 1 4 1 4
// 5
// Sample Output:
// 1 2
// 2 3 4
// 3 4
// 4 1


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Graph
{
private:
    map<int, vector<pair<int, int>>> adjacencyList;

public:
    void insertEdge(int from, int to, int weight); // Add an edge
    bool isEdge(int from, int to); // Check if there is an edge
    int getWeight(int from, int to); // Get the weight of an edge
    vector<int> getAdjacent(int vertex); // Get adjacent vertices
    void printGraph(); // Print the graph
};

void Graph::insertEdge(int from, int to, int weight)
{
    adjacencyList[from].push_back({to, weight}); // Add edge to adjacency list
}

bool Graph::isEdge(int from, int to)
{
    if (adjacencyList.find(from) != adjacencyList.end())
    {
        for (auto it = adjacencyList[from].begin(); it != adjacencyList[from].end(); ++it)
        {
            if (it->first == to)
            {
                return true; // Return true if edge exists
            }
        }
    }
    return false; // Return false if edge doesn't exist
}

int Graph::getWeight(int from, int to)
{
    if (adjacencyList.find(from) != adjacencyList.end())
    {
        for (auto it = adjacencyList[from].begin(); it != adjacencyList[from].end(); ++it)
        {
            if (it->first == to)
            {
                return it->second; // Return the weight of the edge
            }
        }
    }
    return 0; // Return 0 if no edge exists
}

vector<int> Graph::getAdjacent(int vertex)
{
    vector<int> adjacentVertices;

    if (adjacencyList.find(vertex) != adjacencyList.end())
    {
        for (auto it = adjacencyList[vertex].begin(); it != adjacencyList[vertex].end(); ++it)
        {
            adjacentVertices.push_back(it->first); // Add adjacent vertices
        }
    }

    sort(adjacentVertices.begin(), adjacentVertices.end()); // Sort adjacent vertices

    return adjacentVertices;
}

void Graph::printGraph()
{
    set<int> allVertices;

    for (const auto &pair : adjacencyList)
    {
        allVertices.insert(pair.first); // Collect all vertices
        for (const auto &edge : pair.second)
        {
            allVertices.insert(edge.first); // Collect vertices connected by edges
        }
    }

    for (const int vertex : allVertices)
    {
        cout << vertex;

        if (adjacencyList.find(vertex) != adjacencyList.end())
        {
            for (auto edgeIt = adjacencyList[vertex].begin(); edgeIt != adjacencyList[vertex].end(); ++edgeIt)
            {
                int to = edgeIt->first;
                cout << " " << to; // Print connected vertices
            }
        }

        cout << endl;
    }
}

int main()
{
    int noOfLines, operation, vertex, to, fro, weight, source, j;
    vector<int> arr;
    int arrSize;
    Graph g;
    cin >> noOfLines;
    for (int i = 0; i < noOfLines; i++)
    {
        cin >> operation;
        switch (operation)
        {
        case 1:
            cin >> fro;
            cin >> to;
            cin >> weight;
            g.insertEdge(fro, to, weight);
            break;
        case 2:
            cin >> fro;
            cin >> to;
            cout << g.isEdge(fro, to) << "\n"; 
            break;
        case 3:
            cin >> fro;
            cin >> to;
            cout << g.getWeight(fro, to) << "\n"; 
            break;
        case 4:
            cin >> vertex;
            arr = g.getAdjacent(vertex);
            arrSize = arr.size();
            j = 0;
            while (j < arrSize)
            {
                cout << arr[j] << " ";
                j++;
            }
            cout << "\n";
            break;
        case 5:
            g.printGraph(); 
            cout << "\n";
            break;
        }
    }
    return 0;
}
