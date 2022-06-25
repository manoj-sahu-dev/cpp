#include <iostream>
#include <vector>

using namespace std;

int equilibriumIndex(vector<int> &A);
void print(const vector<int> &A, string vn);

int main()
{
    system("clear");
    vector<int> A{-7, 1, 5, 2, -4, 3, 0};
    print(A, "A");
    int result = equilibriumIndex(A);
    cout << "result = " << result << endl;
    return 0;
}

int equilibriumIndex(vector<int> &A)
{
    int i = 0, n = A.size(), sum = 0, lsum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    for (int i = 0; i < n; i++)
    {
        if ((sum - lsum - A[i]) == lsum)
            return i;
        lsum += A[i];
    }

    return -1;
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
