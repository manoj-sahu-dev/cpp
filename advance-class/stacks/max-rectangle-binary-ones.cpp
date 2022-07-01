#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
    for (int i = 0; i < A.size(); i++)
    {
        vector<int> x = A[i];
        print(x);
    }
}
/**
 * @brief Given a 2D binary matrix of integers A containing 0's and 1's of size N x M.
 * Find the largest rectangle containing only 1's and return its area.
 * Note: Rows are numbered from top to bottom and columns are numbered from left to right.
 * A = [
 *  [0, 0, 1]
 *  [0, 1, 1]
 *  [1, 1, 1]
 * ]
 * ans = 2x2 = 4
 * @param A
 * @return int
 */
vector<int> left_smallest(vector<int> &A);
vector<int> right_smallest(vector<int> &A);
int max_area_histogram(vector<int> &A);
int solve(vector<vector<int>> &A);

int main(int argc, char **argv)
{
    system("clear");

    vector<vector<int>> A = {{0, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 0}};
    print(A);
    int result = solve(A);
    cout << "result is " << result << endl;
    return 0;
}
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

int solve(vector<vector<int>> &A)
{
    int ans = 0;
    int rows = A.size(), columns = A[0].size();
    vector<int> currentRow = A[0];
    ans = max_area_histogram(currentRow);
    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (A[i][j] == 1)
            {
                currentRow[j] += 1;
            }
            else
            {
                currentRow[j] = 0;
            }
        }
        int currentAnswer = max_area_histogram(currentRow);
        ans = max(ans, currentAnswer);
    }
    return ans;
}