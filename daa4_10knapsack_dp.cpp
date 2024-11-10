#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0/1 Knapsack
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    // DP table where dp[i][j] represents the maximum value for capacity j with first i items
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Option to include or exclude the current item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Exclude the current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];  // The maximum value we can get
}

int main() {
    int capacity = 50; // Max weight the knapsack can hold
    vector<int> weights = {10, 20, 30}; // Weights of items
    vector<int> values = {60, 100, 120}; // Values of items

    int max_value = knapsack(capacity, weights, values);
    cout << "Maximum value in Knapsack = " << max_value << endl;

    return 0;
}
