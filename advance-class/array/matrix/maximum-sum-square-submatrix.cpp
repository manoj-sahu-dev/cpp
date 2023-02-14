#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Maximum Sum Square SubMatrix
 * Given a 2D integer matrix A of size N x N
 * find a B x B submatrix where B<= N and B>= 1
 * such that the sum of all the elements in the submatrix is maximum.
 * @param argc
 * @param argv
 * @return int
 */
int solve(vector<vector<int>> &A, int B)
{
    int row = A.size();
    int col = A[0].size();
    int maxSum = INT_MIN;

    vector<vector<long>> prefixSum(row + 1, vector<long>(col + 1, 0));
    for (int i = 1; i < row + 1; i++)
    {
        for (int j = 1; j < col + 1; j++)
        {
            prefixSum[i][j] = A[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    for (int i = 1; i < row + 1; i++)
    {
        for (int j = 1; j < col + 1; j++)
        {
            if (i - B >= 0 && j - B >= 0)
            {
                int currSum = 0;
                currSum = prefixSum[i][j] - prefixSum[i - B][j] - prefixSum[i][j - B] + prefixSum[i - B][j - B];
                maxSum = max(maxSum, currSum);
            }
        }
    }

    return maxSum;
}
int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> A = {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 8, 6, 7, 3}, {4, 4, 4, 4, 4}, {5, 5, 5, 5, 5}};
    int B = 3;
    int sum = solve(A, B);

    cout << "sum: " << sum << endl;
    return 0;
}
