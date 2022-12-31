#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;

        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

public:
    /**
     * @brief Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
     * @link https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1 @endlink
     * @param a
     * @param b
     * @param n
     * @param m
     * @return vector<int>
     */
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> merged;
        for (auto x : a)
        {
            merged.push_back(x);
        }
        for (auto y : b)
        {
            merged.push_back(y);
        }
        print(merged);
        // your code here
        int size = merged.size();
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(merged, size, i);
        }

        return merged;
    }

    void print(vector<int> &a)
    {
        for (auto x : a)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};
int main(int argc, char const *argv[])
{
    system("clear");
    Solution sol;
    vector<int> a{10, 5, 6, 2};
    vector<int> b{12, 7, 9};
    int n = a.size();
    int m = b.size();
    sol.print(a);
    sol.print(b);
    vector<int> result = sol.mergeHeaps(a, b, n, m);
    sol.print(result);
    return 0;
}
