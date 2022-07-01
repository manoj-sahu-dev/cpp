#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief Given an array of integers A.
 * value of a array = max(array) - min(array).
 * Calculate and return the sum of values of all possible subarrays of A modulo 109+7.
 * @param A
 * @return int
 */
int solve(vector<int> &A);
vector<int> find_nearest_smallest_left(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= A[i])
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
        st.push(A[i]);
    }
    return res;
}
vector<int> find_nearest_smallest_right(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= A[i])
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
        st.push(A[i]);
    }
    return res;
}
vector<int> find_nearest_greates_left(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= A[i])
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
        st.push(A[i]);
    }
    return res;
}
vector<int> find_nearest_greatest_right(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= A[i])
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

        st.push(A[i]);
    }
    return res;
}
int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{4, 7, 3, 8};
    int ans = solve(A);
    cout << "ans = " << ans << endl;
    return 0;
}

int solve(vector<int> &A)
{
    vector<int> nearest_smallest_left = find_nearest_smallest_left(A);
    vector<int> nearest_smallest_right = find_nearest_smallest_right(A);
    vector<int> nearest_greates_left = find_nearest_greates_left(A);
    vector<int> nearest_greates_right = find_nearest_greatest_right(A);
    int ans = 0, n = A.size();
    int mod = 1000000007;

    for (int i = 0; i < n; i++)
    {
        // subarray in which A[i] is min
        int p1 = nearest_smallest_left[i];
        int p2 = nearest_smallest_right[i];
        long prodMin = ((i - p1) * (p2 - i)) % mod;
        long minContribution = (prodMin * A[i]) % mod;

        // subarray in which A[i] is max
        int p3 = nearest_greates_left[i];
        int p4 = nearest_greates_right[i];
        long prodMax = ((i - p3) * (p4 - i)) % mod;
        long maxContribution = (prodMax * A[i]) % mod;

        // computing ans
        ans = (ans % mod) + ((maxContribution - minContribution) % mod);
        ans = ans % mod;
    }
    if (ans < 0)
    {
        ans = (ans + mod) % mod;
    }
    return (int)(ans % mod);
}
