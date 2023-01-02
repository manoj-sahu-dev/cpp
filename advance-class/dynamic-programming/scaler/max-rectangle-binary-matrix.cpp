#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> left_smallest(vector<int> &A)
    {
        int n = A.size(), i = 0;
        stack<int> st;
        vector<int> minLeft(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && A[st.top()] >= A[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                minLeft[i] = -1;
            }
            else
            {
                minLeft[i] = st.top();
            }
            st.push(i);
        }

        return minLeft;
    }
    vector<int> right_smallest(vector<int> &A)
    {
        int n = A.size(), i = 0;
        stack<int> st;
        vector<int> minRight(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && A[st.top()] >= A[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                minRight[i] = n;
            }
            else
            {
                minRight[i] = st.top();
            }
            st.push(i);
        }

        return minRight;
    }
    int max_area_histogram(vector<int> &A)
    {
        int ans = 0;
        vector<int> prevSmallest = left_smallest(A);
        vector<int> nextSmallest = right_smallest(A);
        print(prevSmallest);
        print(nextSmallest);
        for (int i = 0; i < A.size(); i++)
        {
            int area = abs(nextSmallest[i] - prevSmallest[i] - 1) * A[i];
            ans = max(ans, area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<int>> &A)
    {
        int maximum = INT_MIN;
        vector<int> histogram(A[0].size(), 0);

        for (int i = 0; i < A.size(); i++)
        {

            for (int j = 0; j < histogram.size(); j++)
            {

                if (A[i][j] == 1)
                {
                    histogram[j]++;
                }
                else
                {
                    histogram[j] = 0;
                }
            }
            maximum = max(maximum, max_area_histogram(histogram));
        }
        return maximum;
    }

    void print(vector<int> &A)
    {
        for (auto x : A)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    void print(vector<vector<int>> &A)
    {
        for (auto x : A)
        {
            print(x);
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    vector<vector<int>> A{
        {1, 1, 1},
        {0, 1, 1},
        {0, 0, 0}};

    Solution solution;
    int result = solution.maximalRectangle(A);
    cout << "max rectangles: " << result << endl;
    return 0;
}
