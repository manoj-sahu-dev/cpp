#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int solveRecursive(vector<int> &cost, int n)
    {
        if (n == 1)
            return cost[1];
        if (n == 0)
            return cost[0];
        int ans = cost[n] + min(solveRecursive(cost, n - 1), solveRecursive(cost, n - 2));
        return ans;
    }

    int solveRecursiveTopDown(vector<int> &cost, int n, vector<int> &dp)
    {
        if (n == 1)
            return cost[1];
        if (n == 0)
            return cost[0];

        if (dp[n] == -1)
        {
            dp[n] = cost[n] + min(solveRecursiveTopDown(cost, n - 1, dp), solveRecursiveTopDown(cost, n - 2, dp));
        }

        return dp[n];
    }
    int solveBottomUp(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
    /**
     * @brief You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
     * Once you pay the cost, you can either climb one or two steps.
     * You can either start from the step with index 0, or the step with index 1.
     * Return the minimum cost to reach the top of the floor.
     * @link https://leetcode.com/problems/min-cost-climbing-stairs/ @endlink
     *
     * @param cost
     * @return int
     */
    int solve(vector<int> &cost)
    {
        int n = cost.size();
        int prev = cost[0];
        int pre2 = cost[1];
        for (int i = 2; i < n; i++)
        {
            int ans = cost[i] + min(prev, pre2);
            prev = pre2;
            pre2 = ans;
        }
        return min(prev, pre2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // return min(solveRecursive(cost, n-1), solveRecursive(cost, n-2));
        // vector<int> dp(n+1, -1);
        // return min(solveRecursiveTopDown(cost, n-1, dp), solveRecursiveTopDown(cost, n-2, dp));
        // return solveBottomUp(cost);
        return solve(cost);
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
