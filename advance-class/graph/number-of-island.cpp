#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &matrix, int x, int y, int r, int c)
    {
        if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != 1) // Boundary case for matrix
            return;

        // Mark current cell as visited
        matrix[x][y] = 2;

        dfs(matrix, x + 1, y, r, c);
        dfs(matrix, x, y + 1, r, c);
        dfs(matrix, x - 1, y, r, c);
        dfs(matrix, x, y - 1, r, c);

        dfs(matrix, x - 1, y - 1, r, c);
        dfs(matrix, x + 1, y + 1, r, c);
        dfs(matrix, x - 1, y + 1, r, c);
        dfs(matrix, x + 1, y - 1, r, c);
    }
    /**
     * @brief Given a matrix of integers A of size N x M consisting of 0 and 1. A group of connected 1's forms an island. From a cell (i, j) such that A[i][j] = 1 you can visit any cell that shares a corner with (i, j) and value in that cell is 1.
     * More formally, from any cell (i, j) if A[i][j] = 1 you can visit:
     *
     * (i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
     * (i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.=
     * (i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
     * (i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
     * (i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
     * (i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
     * (i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
     * (i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
     * Return the number of islands.
     *
     * NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.
     *
     */
public:
    void print(vector<vector<int>> &matrix)
    {
        cout << "content of matrix " << matrix.size() << " X " << matrix[0].size() << endl;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int solve(vector<vector<int>> &A)
    {
        int rows = A.size();
        if (rows == 0) // Empty grid boundary case
            return 0;
        int cols = A[0].size();

        int no_of_islands = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (A[i][j] == 1)
                {
                    dfs(A, i, j, rows, cols);
                    no_of_islands += 1;
                }
            }
        }
        return no_of_islands;
    }
};
int main(int argc, const char **argv)
{
    system("clear");
    vector<vector<int>> matrix{
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};

    Solution solution;
    solution.print(matrix);
    int result = solution.solve(matrix);
    cout << result << endl;
    return 0;
}