#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // Knapsack capacity
    vector<int> weights = {15, 5, 5, 10, 5, 10, 10};
    vector<int> values = {800, 200, 500, 300, 600, 700, 400};
    int n = weights.size();

    cout << "Maximum value in the knapsack: " << knapsack(W, weights, values, n) << endl;

    return 0;
}
