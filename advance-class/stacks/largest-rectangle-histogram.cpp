#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> &A)
{
    cout << "content if vecotr: ";
    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

/**
 * @brief Given an array of integers A.
 * A represents a histogram i.e A[i] denotes the height of the ith histogram's bar. Width of each bar is 1.
 * Find the area of the largest rectangle formed by the histogram.
 *
 * @param A
 * @return int
 */
int largestRectangleArea(vector<int> &A);
vector<int> find_prev_smallest(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && A[st.top()] >= A[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            res[i] = -1;
        }
        else
        {
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}
vector<int> find_next_smallest(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && A[st.top()] >= A[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            res[i] = n;
        }
        else
        {
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}
int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{0, 1, 1, 1, 1, 0};
    print(A);
    int ans = largestRectangleArea(A);
    cout << "ans = " << ans << endl;
    return 0;
}

int largestRectangleArea(vector<int> &A)
{
    stack<int> st;
    int ans = 0, n = A.size();
    vector<int> prevSmallest = find_prev_smallest(A);
    vector<int> nextSmallest = find_next_smallest(A);
    print(prevSmallest);
    print(nextSmallest);
    for (int i = 0; i < n; i++)
    {
        int area = abs(nextSmallest[i] - prevSmallest[i] - 1) * A[i];
        // cout << "i = " << i << ", nextSmallest = " << nextSmallest[i] << ", prevSmallest = " << prevSmallest[i] << ", A[i] = " << A[i] << ", area: " << area << endl;
        ans = max(ans, area);
    }
    return ans;
}