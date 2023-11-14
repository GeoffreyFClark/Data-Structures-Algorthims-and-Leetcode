#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
using namespace std;

// Directed graph implemented via adjacency list
class AdjacencyList {
private:
    map<string, vector<string>> graph;  // Adjacency list: map each page to its outgoing links
    set<string> allPages;               // Track each page in the graph
    map<string, double> pageRanks;      // Map each page to its PageRank

    // Initialize ranks of each page to 1 / total number of pages
    void initializeRanks() {
        double initialRank = 1.0 / allPages.size();
        for (const string &page : allPages) {
            pageRanks[page] = initialRank;
        }
    }

    // Calculate PageRank using specified num of iterations
    void calcRank(int iterations) {
        initializeRanks(); 

        for (int i = 1; i < iterations; i++) {
            map<string, double> newRanks;

            // Reset new ranks for each iteration
            for (const string &page : allPages) {
                newRanks[page] = 0.0;
            }

            // Distribute rank of each page to its outlinks
            for (const auto &vertex : graph) {
                string from = vertex.first;  // Current page
                vector<string> outLinks = vertex.second;  // Outlinks from current page
                double rankToDistribute = pageRanks[from] / outLinks.size();  // Rank to distribute

                // Distribute
                for (const string &to : outLinks) {
                    newRanks[to] += rankToDistribute;
                }
            }
            pageRanks = newRanks;
        }
    }

public:
    // Add outlink, track pages "from" and "to"
    void addEdge(const string &from, const string &to) {
        graph[from].push_back(to);
        allPages.insert(from);
        allPages.insert(to);
    }

    // Public method to calculate + print PageRanks
    void calcPrintRank(int powerIterations) {
        calcRank(powerIterations);  // Calculate
        for (const auto &pageRank : pageRanks) {  // Print
            cout << pageRank.first << " " << fixed << setprecision(2) << pageRank.second << endl;
        }
    }
};

int main() {
    int no_of_lines, power_iterations;
    cin >> no_of_lines >> power_iterations;
    AdjacencyList directedGraph;

    for (int i = 0; i < no_of_lines; i++) {
        string from, to;
        cin >> from >> to;
        directedGraph.addEdge(from, to);
    }

    directedGraph.calcPrintRank(power_iterations);
    return 0;
}
