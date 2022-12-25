#include <iostream>
#include <vector>

using namespace std;
class Solution
{
private:
    void permutes(vector<int> &A, int index, vector<vector<int>> &result)
    {
        int n = A.size();
        if (index == n - 1)
        {
            result.push_back(A);
            return;
        }
        for (int i = index; i < n; i++)
        {
            swap(A[i], A[index]);
            permutes(A, index + 1, result);
            swap(A[i], A[index]);
        }
    }

public:
    /**
     * @brief Given an integer array A of size N denoting collection of numbers , return all possible permutations.
     * NOTE:
     * No two entries in the permutation sequence should be the same.
     * For the purpose of this problem, assume that all the numbers in the collection are unique.
     * Return the answer in any order
     *
     * WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
     * Example : next_permutations in C++ / itertools.permutations in python.
     * If you do, we will disqualify your submission retroactively and give you penalty points.
     * @link https://www.scaler.com/academy/mentee-dashboard/class/31392/assignment/problems/138?navref=cl_tt_lst_nm @endlink
     * @param A
     * @return vector<vector<int>>
     */
    vector<vector<int>> permute(vector<int> &A)
    {
        vector<vector<int>> result;
        if (A.size() == 0)
            return result;
        permutes(A, 0, result);
        return result;
    }
    void print(vector<int> &A)
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
    vector<int> A{1, 2, 3};
    Solution solution;
    solution.print(A);
    auto result = solution.permute(A);
    solution.print(result);
    return 0;
}