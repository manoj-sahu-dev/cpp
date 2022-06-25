#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print(const vector<int> &A, string vn = "");
void print(const vector<vector<int> > &A, string vn = "");
vector<int> flipBF(string A);
vector<int> flip(string A);

int main()
{
    system("clear");
    string A = "010";
    cout << "original = " << A << endl;
    vector<int> result = flip(A);
    print(result, "result");
    // result = flipBF(A);
    // print(result, "result brute force");
    return 0;
}

vector<int> flip(string A)
{
    // flip all 1 to -1 & 0 to 1, this way we can get max subarray
    int n = A.length(), i = 0;
    vector<int> vec(n);
    for (i = 0; i < n; i++)
    {
        if (A[i] == '1')
            vec[i] = -1;
        else
            vec[i] = 1;
    }
    // print(vec, "vec");
    int start = 0, end = 0, current = 0, maxV = 0, l = 1;
    for (i = 0; i < n; i++)
    {
        current += vec[i];
        // cout << current << endl;
        if (current < 0)
        {
            l = i + 2;
            current = 0;
        }
        if (current > maxV)
        {
            maxV = current;
            start = l; // the only reason we are adding +1 here is - in answer we need to return 0 based indexing
            end = i + 1;
        }
    }
    cout << "start = " << start << ", end = " << end << ", n = " << n << endl;
    if (start == n || (start == 0 && end == 0))
        return vector<int>();
    return {start, end};
}

vector<int> flipBF(string A)
{
    vector<int> result;
    int n = A.length(), total_ones = 0, count1 = 0, count0 = 0, ans = 0;
    for (auto m : A)
        if (m == '1')
            total_ones += 1;

    ans = total_ones;
    cout << "total_ones = " << total_ones << endl;

    for (int l = 0; l < n; l++)
    {
        int ones = 0;
        count1 = 0, count0 = 0;
        for (int r = 0; r < n; r++)
        {
            if (A[r] == '1')
                count1 += 1;
            else
                count0 += 1;
        }
        ones = total_ones - count1 + count0;
        ans = max(ans, ones);
    }
    return result;
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
