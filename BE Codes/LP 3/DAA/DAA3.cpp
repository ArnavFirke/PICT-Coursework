#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve the 0-1 Knapsack problem using Dynamic Programming
int knapsackDP(int W, vector<int> &weights, vector<int> &values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtracking to find the selected items
    int w = W;
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        { // Item i-1 was included
            // selectedItems.push_back(i - 1); // Store the item's index
            cout << "Included items index: " << i - 1 << endl;
            w -= weights[i - 1]; // Reduce weight
        }
    }

    // The maximum value for the given weight W is in dp[n][W]
    return dp[n][W];
}

int main()
{
    int W, n;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    int maxProfit = knapsackDP(W, weights, values, n);
    cout << "The maximum value that can be obtained is: " << maxProfit << endl;

    return 0;
}
