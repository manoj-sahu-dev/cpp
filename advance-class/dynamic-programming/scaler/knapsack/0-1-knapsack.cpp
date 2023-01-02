#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void print(vector<int> &v)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    void print(vector<vector<int>> &v)
    {
        for (auto x : v)
        {
            print(x);
        }
        cout << endl;
    }
    int solveRecursive(vector<int> &values, vector<int> &weights, int capacity, int current_index)
    {
        // base case
        cout << "current index: " << current_index << ", weight: " << weights[current_index] << ", value: " << values[current_index] << endl;
        // check if we can pick current only if its weight is less or equals capacity
        if (weights[current_index] <= capacity)
        {
            return weights[current_index];
        }
        else
        {
            return 0; // cant pick up
        }

        int include = 0;

        if (weights[current_index] <= capacity)
        {
            include = values[current_index] + solveRecursive(values, weights, capacity - weights[current_index], current_index - 1);
        }
        int exclude = solveRecursive(values, weights, capacity, current_index - 1);

        int ans = max(exclude, include);
        return ans;
    }

    int solveRecursiveMemoisation(vector<int> &values, vector<int> &weights, int capacity, int current_index, vector<vector<int>> &dp)
    {
        // base case
        cout << "current index: " << current_index << ", weight: " << weights[current_index] << ", value: " << values[current_index] << endl;
        if (current_index == 0)
        {
            // check if we can pick current only if its weight is less or equals capacity
            if (weights[current_index] <= capacity)
            {
                return weights[current_index];
            }
            else
            {
                return 0; // cant pick up
            }
        }
        if (dp[current_index][capacity] != -1)
        {
            return dp[current_index][capacity];
        }

        int include = 0;

        if (weights[current_index] <= capacity)
        {
            include = values[current_index] + solveRecursiveMemoisation(values, weights, capacity - weights[current_index], current_index - 1, dp);
        }
        int exclude = solveRecursiveMemoisation(values, weights, capacity, current_index - 1, dp);

        return dp[current_index][capacity] = max(exclude, include);
    }
    int solveTabulation(vector<int> &values, vector<int> &weights, int capacity)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for (int weight = weights[0]; weight <= capacity; weight++)
        {
            if (weights[0] <= capacity)
            {
                dp[0][weight] = values[0];
            }
        }

        for (int current_index = 1; current_index < n; current_index++)
        {
            for (int weight = 0; weight <= capacity; weight++)
            {
                int include = 0;

                if (weights[current_index] <= weight)
                {
                    include = values[current_index] + dp[current_index - 1][weight - weights[current_index]];
                }
                int exclude = dp[current_index - 1][weight];
                dp[current_index][weight] = max(include, exclude);
            }
        }
        return dp[n - 1][capacity];
    }

public:
    /**
     * @brief Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.
     * Also given an integer C which represents knapsack capacity.
     * Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.
     * NOTE:
     * You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
     *
     * @param A values of array to pick up
     * @param B weights of array to pick up
     * @param C capacity of knapsack
     * @return int
     */
    int solve(vector<int> &A, vector<int> &B, int C)
    {
        int ans = 0;
        int n = A.size();
        ans = solveRecursive(A, B, C, n - 1); // recursively solve

        vector<vector<int>> dp(n, vector<int>(C + 1, -1));
        // print(dp);
        // ans = solveRecursiveMemoisation(A, B, C, n - 1, dp);
        // ans = solveTabulation(A, B, C);
        return ans;
    }
};

int main(int argc, char **argv)
{
    system("clear");
    Solution solution;
    vector<int> A{359, 963, 465, 706, 146, 282, 828, 962, 492};
    vector<int> B{96, 43, 28, 37, 92, 5, 3, 54, 93};
    int C = 383;
    int ans = solution.solve(A, B, C);
    cout << "answer: " << ans << endl;
    return 0;
}