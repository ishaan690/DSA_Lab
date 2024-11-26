#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
pair<int, vector<int>> knapsack(vector<int> &values, vector<int> &weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find the items included in the optimal solution
    int max_value = dp[n][capacity];
    vector<int> selected_items;
    int w = capacity;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items.push_back(i - 1);
            w -= weights[i - 1];
        }
    }

    return {max_value, selected_items};
}

int main() {
    // Example usage
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    auto result = knapsack(values, weights, capacity);
    cout << "Maximum Value: " << result.first << endl;

    cout << "Selected Items: ";
    for (int item : result.second) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
