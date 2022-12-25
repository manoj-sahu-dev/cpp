#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @brief You are given an array prices where prices[i] is the price of a given stock on the ith day.
     * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
     * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
     *
     * @param prices
     * @return int
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < n; i++)
        {
            int dif = prices[i] - min_price;
            max_profit = max(max_profit, dif);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};
int main(int argc, char *argv[])
{
    system("clear");
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;
    int maxProfit = solution.maxProfit(prices);
    cout << maxProfit << endl;
    return 0;
}