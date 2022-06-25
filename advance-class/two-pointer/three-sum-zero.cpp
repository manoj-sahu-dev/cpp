#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << "[ " << i << ", " << A[i] << " ], ";
    }
    cout << endl;
}
void print(vector<vector<int> > &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
vector<vector<int> > threeSum(vector<int> &A);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{-1, 0, 1, 2, -1, 4};
    print(A);
    vector<vector<int> > result = threeSum(A);
    print(result);
    return 0;
}

vector<vector<int> > threeSum(vector<int> &A)
{
    vector<vector<int> > result;
    sort(A.begin(), A.end());
    int i = 0, n = A.size(), j = i + 1, k = n - 1, fs = 0;
    while (i < n)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            int sum = A[j] + A[k];
            int requiredSum = fs - A[i];
            if (sum > requiredSum)
            {
                k -= 1;
            }
            else if (sum < requiredSum)
            {
                j += 1;
            }
            else
            {
                cout << " -- > i = " << i << ", j = " << j << ", k = " << k << ", " << A[i] << ", " << A[j] << ", " << A[k] << endl;
                // if ((A[i] <= A[j] && A[j] <= A[k]) )
                bool exist = false;
                for (int m = 0; m < result.size(); m++)
                {
                    vector<int> temp = result[m];
                    print(temp);
                    if (A[i] == temp[0] && A[j] == temp[1] && A[k] == temp[2])
                    {
                        exist = true;
                        break;
                    }
                }
                if (!exist)
                    result.push_back({A[i], A[j], A[k]});
                j += 1;
                k -= 1;
            }
            // cout << "i = " << i << ", j = " << j << ", k = " << k << ", sum = " << sum << ", requiredSum = " << requiredSum << endl;
        }
        i++;
    }
    return result;
}