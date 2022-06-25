#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
void print(vector<vector<int> > &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void printBoard(const vector<string> &A)
{
    for (string a : A)
    {
        int n = a.length();
        for (auto c : a)
        {
            cout << c << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isValidSudoku(const vector<string> &A);

int main(int argc, char **argv)
{
    system("clear");

    // vector<string> A{"..5.....6", "....14...", ".........", ".....92..", "5....2...", ".......3.", "...54....", "3.....42.", "...27.6.."};
    vector<string> A{"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    printBoard(A);
    bool result = isValidSudoku(A);
    cout << "is valid sudoku: " << result << endl;

    return 0;
}

bool isValidSudoku(const vector<string> &A)
{
    set<string> mset;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char character = A[i][j];
            if (character == '.')
                continue;
            string rowStr = "_r_";
            rowStr += to_string(i);
            string columnStr = "_c_";
            columnStr += to_string(j);
            string boardStr = "_b_";
            boardStr += to_string(i / 3);
            boardStr += "_";
            boardStr += to_string(j / 3);

            rowStr.insert(0, 1, character);
            columnStr.insert(0, 1, character);
            boardStr.insert(0, 1, character);
            cout << rowStr << " " << columnStr << " " << boardStr << endl;

            if (mset.find(rowStr) != mset.end() || mset.find(columnStr) != mset.end() || mset.find(boardStr) != mset.end())
            {
                return false;
            }
            else
            {
                mset.insert(rowStr);
                mset.insert(columnStr);
                mset.insert(boardStr);
            }
        }
    }
    return true;
}