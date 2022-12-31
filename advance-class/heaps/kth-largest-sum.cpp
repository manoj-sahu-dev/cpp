#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief Get the Kth Largest
 * you-have-been-given-an-array-list-of-n-integers-now-you-are-supposed-to-find-the-k-th-largest-sum-of-the-subarray
 * You have been given an array/list of ‘N’ integers. Now you are supposed to find the K-th largest sum of the subarray.
 *
 * @param arr
 * @param k
 * @return int
 */
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main(int argc, char const *argv[])
{
    system("clear");
    vector<int> arr{5, 4, -8, 6};
    getKthLargest(arr, 10);
    return 0;
}
