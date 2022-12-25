#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int solveRecursive(vector<int> &A, vector<int> &B, int C)
    {
    }

public:
    int solve(vector<int> &A, vector<int> &B, int C)
    {
        int ans;
        return ans;
    }
};

int main(int argc, char **argv)
{
    system("clear");
    Solution solution;
    vector<int> A{60, 100, 120};
    vector<int> B{10, 20, 30};
    int C = 50;
    int ans = solution.solve(A, B, C);
    cout << "answer: " << ans << endl;
    return 0;
}