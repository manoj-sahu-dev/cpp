#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A, int B)
{
    int ans = -1, left = 0, right = INT_MAX;

    for (int i = 0; i < A.size(); i++)
    {
        right = min(right, A[i]);
    }

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isMinimum(A, mid, B))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (ans == -1)
        return 0;
    return ans;
}
bool isMinimum(vector<int> A, int mid, int B)
{
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
        sum += mid == 0 ? A[i] : (A[i] / mid);
    return sum >= B;
}
int main(int argc, char **argv)
{
    system("clear");
    return 0;
}