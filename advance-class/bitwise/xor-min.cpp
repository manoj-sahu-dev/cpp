#include <iostream>
#include <vector>

using namespace std;
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

int findMinXorBF(vector<int> &A)
{
    sort(A.begin(), A.end());
    int size = A.size(), min = A[0] ^ A[1];
    print(A, "findMinXorBF");
    cout << "n = " << size << ", minVal = " << min << endl;
    for (int i = 2; i < size; i++)
    {
        int xo = A[i - 1] ^ A[i];
        if (xo < min)
            min = xo;
    }
    return min;
}

int findMinXor(vector<int> &A)
{
    // sort(A.begin(), A.end());

    int n = A.size(), minVal = A[0] ^ A[1];
    print(A, "findMinXor");
    cout << "n = " << n << ", minVal = " << minVal << endl;
    for (int i = 2; i < n; i++)
    {
        int xo = A[i - 1] ^ A[i];
        minVal = min(minVal, xo);
        cout << "A[" << i - 1 << "] = " << A[i - 1] << ", A[" << i << "] = " << A[i] << ", xo = " << xo << ", minVal = " << minVal << endl;
    }
    return minVal;
}
int main()
{
    system("clear");

    vector<int> A = {15, 5, 1, 10, 2};
    int result = findMinXor(A);
    cout << "result = " << result << endl;

    // result = findMinXorBF(A);
    // cout << "result bf = " << result << endl;
    return 0;
}

int solve(vector<int> &A)
{
    int n = A.size(), mod = 1000000007;
    long ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int index = n;
        for (int j = n - 1; j >= 0; j--)
        {
            bool bit = (A[j] >> i) & 1;
            if (bit)
            {
                index = j;
            }
            ans = (ans + (n - index) * (pow(2, i)));
            ans %= mod;
        }
    }
    return ans % mod;
}