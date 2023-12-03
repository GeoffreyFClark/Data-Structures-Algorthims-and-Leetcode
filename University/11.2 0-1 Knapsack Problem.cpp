// Backpack Problem / 0-1 Knapsack Problem

// Problem Statement
// There are N items and a backpack with capacity W. Given an array weights representing the weight of each item in the backpack and an array values representing the value of each item. Write a method to find the maximum value you could put into the backpack given the capacity of W. The prototype of the method is as followed: 

// int backpack(int W, vector<int> weights, vector<int> values)

// Constraints
// You cannot split an item
// The total weights of the items that you need to put into the backpack cannot exceed backpack capacity W. 
// Each item can only be chosen once. 

// Input:
// W = 4, weights = [1,1,2,2], values = [1,2,4,5]

// Output:
// 9

// Explanation:
// If we put weights[2] and weights[3] into the backpack, we can get the maximum value of 4 + 5 = 9.
// And the capacity of the backpack is not exceeded.

// Test cases
// The first line of input specifies the capacity of the backpack
// The second line of input lists the weight of each item. 
// The third line of input lists the value of each item.
// The output indicates the maximum value you could put into the backpack of capacity W.

// Sample Input:
// 4
// [1,1,2,2]
// [1,2,4,5]

// Sample Output:
// 9

#include <vector>
#include <algorithm>
using namespace std;

int backpack(int W, vector<int> weights, vector<int> values) {
    int N = weights.size();
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Build table dp[][] bottom-up
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Maximize value: not taking the item vs taking the item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // If the weight of the item is more than the current capacity,
                // just carry forward the value without this item.
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell of the dp table will hold the maximum value
    return dp[N][W];
}