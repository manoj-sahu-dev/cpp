#include <iostream>
#include <vector>

using namespace std;

vector<int> maxset(vector<int> &A);
vector<int> maxsetBF(vector<int> &A);

void print(const vector<int> &A, string vn = "");

int main()
{
    system("clear");
    vector<int> A{1, 2, 5, -7, 2, 5};
    print(A, "A");

    vector<int> result = maxsetBF(A);
    print(result, "result bruite force");
    result = maxset(A);
    print(result, "result");
    return 0;
}

vector<int> maxset(vector<int> &A)
{
    vector<int> result;
    int n = A.size(), i = 0, ps = 0, tempI = -1, minI = 0, maxI = 0, msum = 0, temp = 0;
    for (i = 0; i < n; i++)
    {
        if (A[i] <= 0)
        {
            ps = 0;
            tempI = i;
        }
        else
        {
            ps += A[i];
            temp = msum;
            msum = max(msum, ps);
            if (msum > temp)
            {
                minI = tempI + 1;
                maxI = i;
            }
        }
        cout << i << "=>  ps: " << ps << ", minI " << minI << ", maxI " << maxI << endl;
    }
    for (int i = minI; i <= maxI; i++)
    {
        result.push_back(A[i]);
    }
    return result;
}

vector<int> maxsetBF(vector<int> &A)
{
    vector<int> result;
    int minI = 0, maxI = 0, n = A.size(), sum = 0, temp = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0)
        {
            for (int j = i; j < n; j++)
            {
                sum = 0;
                int m = i;
                if (A[j] >= 0)
                {
                    for (m = i; m <= j; m++)
                    {
                        sum += A[m];
                        // cout << A[m] << " ";
                    }
                }
                else
                {
                    break;
                }
                if (sum > temp)
                {
                    temp = sum;
                    minI = i;
                    maxI = j;
                }
                // cout << "sum = " << sum << endl;
            }
        }
    }
    for (int i = minI; i <= maxI; i++)
    {
        result.push_back(A[i]);
    }
    return result;
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
