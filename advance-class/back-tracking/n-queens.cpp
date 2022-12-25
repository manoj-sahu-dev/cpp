#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    bool is_safe(int row, int column, vector<vector<string>> &board, int board_size)
    {
        int x = row;
        int y = column;

        while (y >= 0)
        {
            if (board[x][y] == "Q")
                return false;
            y -= 1;
        }

        x = row;
        y = column;

        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == "Q")
                return false;
            y -= 1;
            x -= 1;
        }

        x = row;
        y = column;

        while (x < board_size && y >= 0)
        {
            if (board[x][y] == "Q")
                return false;
            y -= 1;
            x += 1;
        }

        return true;
    }

    void solve_board(vector<vector<string>> &board, vector<vector<string>> &ans, int board_size)
    {
        vector<string> temp;
        for (int i = 0; i < board_size; i++)
        {
            string s = "";
            for (int j = 0; j < board_size; j++)
            {
                s += board[i][j];
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    void solve(int column, vector<vector<string>> &board, vector<vector<string>> &ans, int board_size)
    {
        if (column == board_size) // base case
        {
            solve_board(board, ans, board_size);
            return;
        }

        for (int row = 0; row < board_size; row++)
        {
            if (is_safe(row, column, board, board_size))
            {
                board[row][column] = "Q";
                solve(column + 1, board, ans, board_size);
                board[row][column] = ".";
            }
        }
    }

public:
    /**
     * @brief The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
     * Given an integer A, return all distinct solutions to the n-queens puzzle.
     * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
     * The final list should be generated in such a way that the indices of the queens in each list should be in reverse lexicographical order.

     *
     * @param A
     * @return vector<vector<string>>
     */
    vector<vector<string>> solveNQueens(int A)
    {
        vector<vector<string>> ans;
        vector<vector<string>> board(A, vector<string>(A, "."));
        print(board);
        solve(0, board, ans, A);
        return ans;
    }

    void print(vector<string> &A)
    {
        for (auto num : A)
        {
            cout << num;
        }
        cout << endl;
    }

    void print(vector<vector<string>> &A)
    {
        for (auto vec : A)
        {
            print(vec);
        }
        cout << endl;
    }
};

int main(int argc, char **argv)
{
    system("clear");
    cout << "enter size of board: ";
    int n = 0;
    cin >> n;

    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(n);
    solution.print(result);
}