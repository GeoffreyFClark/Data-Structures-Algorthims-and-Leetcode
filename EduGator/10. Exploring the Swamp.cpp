// Exploring the swamp

// Problem Statement
// Explorer Albert, a coffee bean aficionado, is passing through a swamp while simultaneously trying to pick up as many coffee beans as possible. The swamp is represented by a m x n integer array, swamp, where swamp[i][j] represents the number of coffee beans located at row i, column j of the swamp.

// Albert always enters the swamp at row 0, column 0, and always exits the swamp at row m, column n. At each step, he moves either one unit to the right (across one column) or one unit down (across one row).

// When Albert visits swamp[i][j], he collects all the coffee beans at that location. Write a function that returns the maximum number of coffee beans that Albert can collect as he traverses through the swamp. Implement your solution using dynamic programming.

// Example input
// 3 3
// 5 3 4
// 8 6 9
// 1 3 2

// Example output
// 30

// Explanation
// Input consists of m+1 lines

// Line 1 of input denotes two integers m representing number of rows and n representing number of columns.

// m lines follow in the input, each line repesenting a row in the grid and containing n integers each representing the number of coffee beans.

// Output is the global optimal.

// In the example input, it is calculated as 5 + 8 + 6 + 9 + 2 = 30 which is the maximum number of coffee beans that Albert can pick up.

#include <iostream>
#include <cstdlib>
#include <vector>

int swampExplorer(std::vector<std::vector<int>>& swamp) {
    int m = swamp.size();
    int n = swamp[0].size();

    // Sum the cells of the first column, representing the path when moving straight down from the top-left.
    for (int i = 1; i < m; ++i) {
        swamp[i][0] += swamp[i - 1][0];
    }

    // Sum the cells of the first row, representing the path when moving straight right from the top-left.
    for (int j = 1; j < n; ++j) {
        swamp[0][j] += swamp[0][j - 1];
    }

    // Calculate the maximum beans that can be collected in each cell, using the maximum sum from either the top or left cell.
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            swamp[i][j] += std::max(swamp[i - 1][j], swamp[i][j - 1]);
        }
    }

    // The bottom-right cell contains the total number of beans collected on the maximized path through the swamp.
    return swamp[m - 1][n - 1];
}
