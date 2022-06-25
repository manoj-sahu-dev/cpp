#include <iostream>
#include <vector>
#include <set>

using namespace std;
int firstMissingPositive(vector<int> &A);
int main()
{
    system("clear");
    vector<int> A{2, 3, 1, 2}; // 1, 2, 0 //3, 4, -1, 1 //-8, -7, -6
    int res = firstMissingPositive(A);
    cout << "result: " << res << endl;
    return 0;
}

int firstMissingPositive(vector<int> &A)
{
    int value = 1;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
        cout << " " << A[i] << endl;
    bool found = false;
    int si = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == value)
        {
            found = true;
            si = i;
        }
    }
    if (found)
    {
        int i = 0;
        for (i = si; i < A.size() - 1; i++)
        {
            if (A[i] == A[i + 1])
                continue;
            if ((A[i] + 1) != A[i + 1])
            {
                cout << "inner here!";
                return A[i] + 1;
            }
        }
        return A[i] + 1;
    }
    return value;
}