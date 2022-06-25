#include <iostream>
#include <vector>

using namespace std;

int pickFromBothSides(vector<int> &A, int B);
void print(const vector<int> &A, string vn);

int main()
{
    system("clear");
    vector<int> A{5, -2, 3, 1, 2};
    int B = 3;
    print(A, "A");
    int result = pickFromBothSides(A, B);
    cout << "result = " << result << endl;
    return 0;
}

int pickFromBothSides(vector<int> &A, int B)
{
    int i = 0, n = A.size(), sum = 0, ans = INT_MIN;

    for (int i = 0; i < B; i++)
    {
        sum += A[i];
    }
    int lastIndex = n - 1;
    for (int i = B - 1; i >= 0; i--)
    {
        sum = sum - A[i] + A[lastIndex];
        ans = max(ans, sum);
        lastIndex -= 1;
    }
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
