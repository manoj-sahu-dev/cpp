#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
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
    int i = 0, j = 1, n = A.size(), k = n - 1, target = 0;
    while (i < j)
    {
        int targetSum = target - A[i];
        j = i + 1;
        k = n - 1;
        cout << "\ntarget sum = " << targetSum << endl;
        while (j < k)
        {
            int currentSum = A[j] + A[k];
            cout << "current sum = " << currentSum << ", A[" << j << "] = " << A[j] << ", A[" << k << "] = " << A[k] << endl;
            if (currentSum > targetSum)
            {
                k--;
            }
            else if (currentSum < targetSum)
            {
                j++;
            }
            else
            {
                result.push_back({A[i], A[j]});
            }
            sleep(1);
        }
        i++;
    }
    return result;
}