#include <iostream>
#include <vector>

using namespace std;

string FindLittlePony(string A);
int solve(vector<int> &A);
bool findAllSubsetSum(vector<int> &A, int target);
int main()
{
    // string A;
    // cout << "enter a string: ";
    // cin >> A;
    // A = FindLittlePony(A);
    // cout << "result: " << A << endl;

    vector<int> A{1, 20, 13, 4, 5};
    solve(A);
    bool exist = findAllSubsetSum(A, 18);
    cout << "result: " << exist << endl;
    return 0;
}

bool findAllSubsetSum(vector<int> &A, int target)
{
    int n = A.size(), sr = 1 << n;

    for (int i = 0; i < sr; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i && (1 << j) > 0)
            {
                sum += A[j];
            }
            cout << "i = " << i << ", j = " << j << ", res = " << (1 << j) << ", res2: " << (i && (1 << j)) << ", sum = " << sum << endl;
        }
        if (sum == target)
        {
            cout << "exists " << endl;
            return true;
        }
    }
    return false;

    int n = A.length;
    if (n == 1)
        return n;
    int next = 1 - (A[0] % 2);
    int len = 1;

    for (int i = 1; i < n; i++)
    {
        if (A[i] % 2 == next)
        {
            len++;
            next = 1 - (A[i] % 2);
        }
    }

    return len;
}
int solve(vector<int> &A, int B)
{
    if (B == 0)
        return 1;
    int pow = 1 << A.size();

    for (int i = 0; i < pow; i++)
    {
        int x = 0, sum = 0, cn = i;

        while (cn > 0)
        {
            if ((cn & 1) == 1)
            {
                sum += A[x];
            }
            x++;
            cn = cn >> 1;
        }

        if (sum == B)
            return 1;
    }

    return 0;
}

int solve(vector<int> &A)
{
    int n = A.size(), result = 0, ts = 0;
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i; j < n; j++)
        {
            int ls = 0;
            for (int k = i; k <= j; k++)
            {
                cout << A[k] << " ";
                ls += A[k];
            }
            ts += ls;
            cout << endl;
            // cout << "ls: " << ls << ", ts: " << ts << endl;
        }
    }

    return result;
}

string FindLittlePony(string A)
{
    int i = 0, minChar = 255, fid, len = A.length();

    for (i = 0; i < len - 1; i++)
    {
        if (minChar > A[i])
        {
            minChar = A[i];
            fid = i;
        }
    }
    string result = "";
    result += minChar;

    minChar = 255;
    for (i = fid + 1; i < len; i++)
    {
        if (minChar > A[i])
        {
            minChar = A[i];
        }
    }
    result += minChar;

    return result;
}