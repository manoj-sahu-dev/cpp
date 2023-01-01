#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    /**
     * @brief There are given N ropes of different lengths. we need to connect these ropes into one rope.
     * The cost to connect two ropes is equal to sum of their lengths, The task is to connect the ropes with minimum cost.
     * Given N size array arr[] contains the lengths of the ropes.
     *
     * @param arr
     * @param n
     * @return long long
     */
    long long minCost(long long arr[], long long n)
    {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        print(pq);
        long long cost = 0;
        while (pq.size() > 1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = 0;
            second = pq.top();
            pq.pop();

            long long sum = first + second;
            cost += sum;
            cout << "first: " << first << ", second: " << second << ", cost: " << cost << ", size = " << pq.size() << endl;
            pq.push(sum);
        }
        return cost;
    }
    void print(priority_queue<long long, vector<long long>, greater<long long>> gq)
    {
        while (!gq.empty())
        {
            cout << gq.top() << "  ";
            gq.pop();
        }

        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    long long arr[] = {4, 3, 2, 6};
    int n = 4;
    Solution solution;
    long long ans = solution.minCost(arr, n);
    cout << "min cost: " << ans << endl;
    return 0;
}
