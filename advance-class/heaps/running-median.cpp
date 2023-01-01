#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    void print(vector<int> &v)
    {
        for (auto x : v)
            cout << x << "  ";
        cout << endl;
    }
    /**
     * @brief Given an array of integers, A denoting a stream of integers. New arrays of integer B and C are formed.
     * Each time an integer is encountered in a stream, append it at the end of B and append the median of array B at the C.
     *
     * Find and return the array C.
     *
     * NOTE:
     * If the number of elements is N in B and N is odd, then consider the median as B[N/2] ( B must be in sorted order).
     * If the number of elements is N in B and N is even, then consider the median as B[N/2-1]. ( B must be in sorted order).
     *
     * @link https://www.scaler.com/academy/mentee-dashboard/class/31388/assignment/problems/4369 @endlink
     * @param A
     *
     * @return vector<int>
     */
    vector<int> solve(vector<int> &A)
    {
        print(A);
        if (A.size() == 1)
            return A; // if  array size is 1

        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        vector<int> ans;

        max_heap.push(min(A[0], A[1]));
        ans.push_back(A[0]);
        min_heap.push(max(A[0], A[1]));
        ans.push_back(max_heap.top());

        for (int i = 2; i < A.size(); i++)
        {
            if (A[i] > max_heap.top())
            {
                min_heap.push(A[i]);
                if (min_heap.size() > max_heap.size())
                {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }
            else
            {
                max_heap.push(A[i]);
                if (max_heap.size() - min_heap.size() > 1)
                {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                }
            }
            ans.push_back(max_heap.top());
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    vector<int> A{1, 2, 5, 4, 3};
    // vector<int> A{5, 17, 100, 11};

    Solution solution;
    vector<int> result = solution.solve(A);
    solution.print(result);
    return 0;
}
