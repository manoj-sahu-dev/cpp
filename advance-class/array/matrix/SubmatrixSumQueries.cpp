#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void print(const vector<int> &A, string vn = "");
void print(const vector<vector<int> > &A, string vn = "");
int findMod(int num);
vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E);

int main()
{
    system("clear");
    vector<vector<int> > A{{5, 17, 100, 11}, {0, 0, 2, 8}};
    vector<int> B{1, 1};
    vector<int> C{1, 4};
    vector<int> D{2, 2};
    vector<int> E{2, 4};
    print(A, "Matrix A");
    vector<int> result = solve(A, B, C, D, E);
    print(result, "result");
    return 0;
}

vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E)
{
    int mod = 1000000009, rows = A.size(), columns = A[0].size(), sum = 0, i = 0, j = 0;
    cout << "rows: " << rows << ", columns: " << columns << endl;
    for (i = 0; i < rows; i++)
    {
        sum = A[i][0];
        for (j = 1; j < columns; j++)
        {
            sum = findMod(sum + A[i][j]);
            A[i][j] = sum;
        }
    }

    print(A, " row");
    for (i = 0; i < columns; i++)
    {
        sum = A[0][i];
        for (j = 1; j < rows; j++)
        {
            sum = findMod(sum + A[j][i]);
            A[j][i] = sum;
        }
    }

    print(A, "columns");

    int bsize = B.size(), ans = 0;
    vector<int> result;

    for (i = 0; i < bsize; i++)
    {
        ans = A[D[i] - 1][E[i] - 1];
        if (B[i] > 1)
        {
            ans -= A[B[i] - 2][E[i] - 1];
        }
        if (C[i] > 1)
        {
            ans -= A[D[i] - 1][C[i] - 2];
        }
        if (B[i] > 1 && C[i] > 1)
        {
            ans = ans + A[B[i] - 2][C[i] - 2];
        }
        result.push_back(findMod(ans));
    }
    return result;
}
long reverse(long A)
{

    int count = 32;
    long sum = 0;
    long one = 1;
    while (A > 0)
    {
        sum = sum + ((A & 1) * (one << (count - 1)));
        A = A >> 1;
        count--;
    }
    return sum;
}

int onesComplement(int n)
{
    int bits = (int)(floor(log(n) / log(2))) + 1;
    return ((1 << bits) - 1) ^ n;
}

int solve(int A)
{
    int x = onesComplement(A);
    int y = (A | x) + 1;
    return x ^ y;
}

string addBinary(string A, string B)
{
    string digits = "";
    int carry = 0;
    int i = A.length() - 1;
    int j = B.length() - 1;
    while (i >= 0 || j >= 0 || carry == 1)
    {
        carry += (i >= 0) ? A[i] - '0' : 0;
        carry += (j >= 0) ? B[j] - '0' : 0;
        digits = to_string(carry % 2) + digits;
        carry /= 2;
        i--;
        j--;
    }
    return digits;
}

int findMod(int num)
{
    int mod = 1e9 + 7;
    int result = num % mod;
    return result > 0 ? result : (result + mod) % mod;
}
int solve(vector<vector<int> > &A, int B)
{
    int n = A.size(), i = 0, j = A[0].size() - 1, res = INT_MAX;
    while (i < n && j >= 0)
    {
        if (A[i][j] == B)
        {
            res = min(res, ((i + 1) * 1009 + (j + 1)));
            j--;
        }
        else if (A[i][j] < B)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return res == INT_MAX ? -1 : res;
}
void print(const vector<int> &A, string vn)
{
    if (vn != "")
        cout << "vector " << vn << " values: " << endl;
    for (auto a : A)
    {
        cout << a << " ";
    }
    cout << endl;
}

void print(const vector<vector<int> > &A, string vn)
{
    cout << "vector " << vn << " values: " << endl;
    for (vector<int> a : A)
    {
        print(a, "");
    }
    cout << endl;
}
