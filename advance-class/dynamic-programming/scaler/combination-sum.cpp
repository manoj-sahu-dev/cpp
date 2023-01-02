#include <bits/stdc++.h>
using namespace std;

int waysRecursive(vector<int> &num, int target)
{
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += waysRecursive(num, target - num[i]);
    }
    return ans;
}

int waysRecursiveTopDown(vector<int> &num, int target, vector<int> &dp)
{
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;

    if (dp[target] != -1)
        return dp[target];

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += waysRecursiveTopDown(num, target - num[i], dp);
    }
    dp[target] = ans;
    return dp[target];
}

int waysBottomUp(vector<int> &num, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[target];
}

/**
 * @brief You are given an array of distinct integers and you have to tell how many different ways of selecting
 * the elements from the array are there such that the sum of chosen elements is equal to the target number tar.
 *
 * @param num
 * @param tar
 * @return int
 */
int findWays(vector<int> &num, int tar)
{
    int sum = 0;
    // sum = waysRecursive(num, tar);

    int n = num.size();
    vector<int> dp(tar + 1, -1);
    // sum = waysRecursiveTopDown(num, tar, dp);
    sum = waysBottomUp(num, tar);
    return sum;
}

int main(int argc, char const *argv[])
{
    system("clear");
    vector<int> num{1, 2, 5};
    int target = 5;
    int sum = findWays(num, target);
    cout << sum << endl;
    return 0;
}
