#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @brief Given a positive integer A, write a program to find the Ath Fibonacci number.
     * In a Fibonacci series, each term is the sum of the previous two terms and the first two terms of the series are 0 and 1.
     * i.e. f(0) = 0 and f(1) = 1. Hence, f(2) = 1, f(3) = 2, f(4) = 3 and so on.
     * NOTE: 0th term is 0. 1th term is 1 and so on.
     * @link https://www.scaler.com/academy/mentee-dashboard/class/31396/assignment/problems/4035?navref=cl_tt_lst_nm @endlink
     * @param num
     * @param dp
     * @return int
     */
    int find_ath_fibonacci(int num, vector<int> &dp)
    {
        // top down approach
        // SC: O(N), TC: O(N)
        if (num <= 1)
            return num;

        if (dp[num] != -1)
        {
            return dp[num];
        }

        return dp[num] = find_ath_fibonacci(num - 1, dp) + find_ath_fibonacci(num - 2, dp);
    }

    int fibo(int num, vector<int> &dp)
    {
        // bottoms up
        //  SC: O(N), TC: O(N)
        if (num <= 1)
        {
            return num;
        }
        for (int i = 2; i <= num; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[num];
    }
    int fibbo(int num)
    {
        //  SC: O(1), TC: O(N)
        if (num <= 1)
            return num;

        int first = 0, second = 1, last = 0;
        for (int i = 2; i <= num; i++)
        {
            last = first + second;
            first = second;
            second = last;
        }
        return last;
    }
};

int main(int argc, const char **argv)
{
    system("clear");
    cout << "enter a term: ";
    int num = 0;
    cin >> num;
    vector<int> dp(num + 1, -1);
    Solution solution;
    int result = 0;
    result = solution.find_ath_fibonacci(num, dp); // top down
    cout << result << endl;
    // bottoms up
    dp[0] = 0;
    dp[1] = 1;
    result = solution.fibo(num, dp);
    cout << result << endl;
    // space optimized
    result = solution.fibbo(num);
    cout << result << endl;
    return 0;
}