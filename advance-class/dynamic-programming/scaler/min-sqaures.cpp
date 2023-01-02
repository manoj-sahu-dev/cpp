#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int countMinSquaresRecursive(int A)
    {
        if (A == 0)
        {
            return 0;
        }

        int count = A;
        for (int i = 1; i * i <= A; i++)
        {
            int temp = i * i;
            count = min(1 + countMinSquaresRecursive(A - temp), count);
        }
        return count;
    }

    int countMinSquaresTopDown(int A, vector<int> &dp)
    {
        if (A == 0)
        {
            return 0;
        }
        cout << "yes" << endl;
        if (dp[A] != -1)
        {
            return dp[A];
        }
        int count = A;
        for (int i = 1; i * i <= A; i++)
        {
            int temp = i * i;
            count = min(1 + countMinSquaresTopDown(A - temp, dp), count);
        }
        dp[A] = count;

        return dp[A];
    }

    int countMinSquaresBottomUp(int A)
    {
        vector<int> dp(A + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= A; i++)
        {
            for (int j = 1; j * j <= A; j++)
            {
                int temp = j * j;
                if (i - temp >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
        return dp[A];
    }

public:
    /**
     * @brief Given an integer A. Return minimum count of numbers, sum of whose squares is equal to A.
     *
     * @param A a number
     * @return int minimum count of numbers, sum of whose squares is equal to A.
     */
    int countMinSquares(int A)
    {
        int squares = 0;
        // squares = countMinSquaresRecursive(A);

        vector<int> dp(A + 1, -1);
        // squares = countMinSquaresTopDown(A, dp);
        squares = countMinSquaresBottomUp(A);
        return squares;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    int number = 0;
    cout << "enter a number: ";
    cin >> number;

    Solution solution;
    int x = solution.countMinSquares(number);
    cout << "minimum squares: " << x << endl;
    return 0;
}
