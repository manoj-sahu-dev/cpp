#include <iostream>
#include <vector>
#include <set>

using namespace std;
int maxAbsolute(vector<int> &A);
int main()
{
    system("clear");
    vector<int> A{1, 3, -1};
    return 0;
}

int maxAbsolute(vector<int> &A)
{
    int maxVal = 0, x, y, xMax = INT_MIN, yMin = INT_MAX;

    for (int i = 0; i < A.size(); i++)
    {
        x = A[i] - i;
        xMax = max(xMax, x);

        y = A[i] + i;
    }
    return maxVal;
}