#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1).
 * Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
 * Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
 *
 * @link https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 @endlink
 * @param m
 * @param n
 * @return vector<string>
 */

class Solution
{
private:
    bool is_safe(int n, vector<vector<int>> &A, vector<vector<bool>> &visited, int x, int y)
    {
        return ((x >= 0 && x < n) && (y >= 0 && y < n) && !visited[x][y] && A[x][y] == 1);
    }

    void get_path(vector<vector<int>> &A, vector<string> &ans, vector<vector<bool>> &visited, string path, int n, int x, int y)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // four ways to visit D, L, R and U
        visited[x][y] = true;

        // D - down
        if (is_safe(n, A, visited, x + 1, y))
        {
            get_path(A, ans, visited, path + "D", n, x + 1, y);
        }

        // L - left
        if (is_safe(n, A, visited, x, y - 1))
        {
            get_path(A, ans, visited, path + "L", n, x, y - 1);
        }

        // R - right
        if (is_safe(n, A, visited, x, y + 1))
        {
            get_path(A, ans, visited, path + "R", n, x, y + 1);
        }

        // U - up
        if (is_safe(n, A, visited, x - 1, y))
        {
            get_path(A, ans, visited, path + "U", n, x - 1, y);
        }
        visited[x][y] = false;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        string path = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        get_path(m, ans, visited, path, n, 0, 0);
        return ans;
    }

    void print(vector<int> &A)
    {
        for (auto num : A)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    void print(vector<string> &A)
    {
        for (auto num : A)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    void print(vector<vector<int>> &A)
    {
        for (auto vec : A)
        {
            print(vec);
        }
    }
};

int main(int argc, char **argv)
{
    system("clear");
    vector<vector<int>> A{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    Solution solution;
    cout << "maze: " << endl;
    solution.print(A);
    auto path = solution.findPath(A, A.size());
    cout << "path: " << endl;
    solution.print(path);
}