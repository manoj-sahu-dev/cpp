#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @brief There are N jobs to be done, but you can do only one job at a time.
     * Given an array A denoting the start time of the jobs and an array B denoting the finish time of the jobs.
     * Your aim is to select jobs in such a way so that you can finish the maximum number of jobs.
     * Return the maximum number of jobs you can finish.
     *
     * @param A
     * @param B
     * @return int
     */
    int solve(vector<int> &A, vector<int> &B)
    {
        return 0;
    }
};

int main(int argc, char **argv)
{
    vector<int> A{1, 5, 7, 1};
    vector<int> B{7, 8, 8, 8};
    Solution solution;
    int result = solution.solve(A, B);
    cout << "result: " << result << endl;
}