#include <iostream>
#include <vector>

using namespace std;

int trap(const vector<int> &A);
int trapOptimized(const vector<int> &A);
void print(const vector<int> &A, string vn);

int main()
{
    system("clear");
    vector<int> A{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; //{3, 0, 0, 2, 0, 4};
    int result = trap(A);
    cout << "result: " << result << endl;

    result = trapOptimized(A);
    cout << "result optimized: " << result << endl;
    return 0;
}
int trapOptimized(const vector<int> &A)
{
    int n = A.size(), l = 0, r = n - 1, maxl = 0, maxr = 0, ans = 0;
    while (l < r)
    {
        maxl = max(maxl, A[l]);
        maxr = max(maxr, A[r]);
        if (maxl > maxr)
        {
            ans += (maxr - A[r--]);
        }
        else
        {
            ans += (maxl - A[l++]);
        }
        cout << "maxl: " << maxl << ", maxr: " << maxr << ", A[" << l << "] = " << A[l] << ", A[" << r << "] = " << A[r] << ", ans: " << ans << endl;
    }
    return ans;
}
int trap(const vector<int> &A)
{
    int n = A.size(), ans = 0, ml = INT_MIN, mr = INT_MIN, i = 0;
    vector<int> mleft, mright, minE;
    print(A, "A");

    for (i = 0; i < n; i++)
    {
        ml = max(A[i], ml);
        mleft.push_back(ml);
    }
    print(mleft, "mleft");

    for (i = n - 1; i >= 0; i--)
    {
        mr = max(A[i], mr);
        mright.push_back(mr);
    }
    reverse(mright.begin(), mright.end());
    print(mright, "mright");
    for (i = 0; i < n; i++)
    {
        minE.push_back(min(mleft[i], mright[i]));
        ans += (minE[i] - A[i]);
    }
    print(minE, "minE");
    print(A, "A");

    return ans;
}
void print(const vector<int> &A, string vn)
{
    cout << "vector " << vn << " values: " << endl;
    for (auto a : A)
    {
        cout << a << " ";
    }
    cout << endl;
}