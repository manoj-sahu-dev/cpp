#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief Given an integer array A of size N. You have to generate it's all subarrays having a size greater than 1.
 * Then for each subarray, find Bitwise XOR of its maximum and second maximum element.
 * Find and return the maximum value of XOR among all subarrays.
 *
 * @param A
 * @return int
 */
int solve(vector<int> &A);

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{1, 3};
    int ans = solve(A);
    cout << "ans = " << ans << endl;
    return 0;
}

int solve(vector<int> &A)
{
    stack<int> st;
    int ans = 0, n = A.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty())
        {
            int secondMax = A[st.top()];
            ans = max(ans, A[i] ^ secondMax);
            if (A[i] < secondMax)
            {
                break;
            }
            st.pop();
        }
        st.push(i);
    }
    return ans;
}