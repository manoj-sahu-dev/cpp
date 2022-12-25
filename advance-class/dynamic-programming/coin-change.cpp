#include <iostream>
#include <vector>

using namespace std;
class Solution
{
private:
    int solveRecursive(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int minimumAmount = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveRecursive(coins, amount - coins[i]);
            if (ans != -1)
            {
                minimumAmount = min(minimumAmount, 1 + ans);
            }
        }
        return minimumAmount;
    }
    int solveRecursiveTopDown(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        int minimumAmount = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solveRecursive(coins, amount - coins[i]);
            if (ans != -1)
            {
                minimumAmount = min(minimumAmount, 1 + ans);
            }
        }
        dp[amount] = minimumAmount;
        return dp[amount];
    }
    int solve(vector<int> &coins, int amount)
    {
        vector<int> stacks(amount + 1, 0);
        int count = 0;
        for (int i = 1; i <= amount; i++)
        {
            stacks[i] = amount + 1;
            for (auto coin : coins)
            {
                cout << "count: " << ++count << ", coin: " << coin << ", i: " << i << " ";
                if (coin <= i)
                {
                    stacks[i] = min(stacks[i], 1 + stacks[i - coin]);
                    cout << "stack: " << stacks[i] << endl;
                }
                else
                {
                    cout << endl;
                }
            }
        }
        return stacks[amount] == amount + 1 ? -1 : stacks[amount];
    }

public:
    /**
     * @brief You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
     * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
     * You may assume that you have an infinite number of each kind of coin.
     * @link https://leetcode.com/problems/coin-change/ @endlink
     *
     * @param coins
     * @param amount
     * @return int
     */
    int coinChange(vector<int> &coins, int amount)
    {
        // return solveRecursive(coins, amount);
        // vector<int> dp(amount + 1, -1);
        // return solveRecursiveTopDown(coins, amount, dp);
        return solve(coins, amount);
    }
};
int main(int argc, char const *argv[])
{
    system("clear");
    vector<int> coins{1, 2, 5};
    Solution solution;
    int res = solution.coinChange(coins, 11);
    cout << "solution: " << res << endl;
    return 0;
}
