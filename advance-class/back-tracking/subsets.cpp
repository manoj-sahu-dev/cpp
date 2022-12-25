#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void subset(vector<int> &A, int index, vector<int> &current, vector<vector<int>> &result)
    {
        if (index == A.size())
        {
            result.push_back(current);
            return;
        }
        subset(A, index + 1, current, result);
        current.push_back(A[index]);
        subset(A, index + 1, current, result);
        current.pop_back();
    }

public:
    /**
     * @brief Given a set of distinct integers A, return all possible subsets.
     * NOTE:
     * Elements in a subset must be in non-descending order.
     * The solution set must not contain duplicate subsets.
     * Also, the subsets should be sorted in ascending ( lexicographic ) order.
     * The list is not necessarily sorted.
     * @param A
     * @return vector<vector<int>>
     */
    vector<vector<int>> subsets(vector<int> &A)
    {
        vector<vector<int>> result;
        vector<int> current;
        sort(A.begin(), A.end());

        subset(A, 0, current, result);
        sort(result.begin(), result.end());
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
    vector<vector<int>> result = solution.subsets(A);
    solution.print(result);
}