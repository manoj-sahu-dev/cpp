#include <iostream>
#include <vector>

using namespace std;

int maxArr(vector<int> &A);
int maxArrBF(vector<int> &A);
void print(const vector<int> &A, string vn = "");
void print(const vector<vector<int> > &A, string vn = "");

int main()
{
    system("clear");
    vector<int> A{1, 3, -1};
    int result = maxArr(A);
    cout << "result = " << result << endl;
    result = maxArrBF(A);
    cout << "result bf = " << result << endl;
    return 0;
}

int maxArr(vector<int> &A)
{
    int xMax = INT_MIN, xMin = INT_MAX, yMax = INT_MIN, yMin = INT_MAX, i = 0, n = A.size();

    for (int i = 0; i < n; i++)
    {
        xMax = max(xMax, A[i] + i);
        xMin = min(xMin, A[i] + i);
        yMax = max(yMax, A[i] - i);
        yMin = min(yMin, A[i] - i);
    }
    return max(xMax - xMin, yMax - yMin);
}

int maxArrBF(vector<int> &A)
{
    int n = A.size(), diff = 0, result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diff = abs(A[i] - A[j]) + (i - j);
            result = max(result, diff);
        }
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
