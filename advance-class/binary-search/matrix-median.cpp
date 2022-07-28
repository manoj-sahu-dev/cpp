#include <iostream>
#include <vector>

using namespace std;

int findMedian(vector<vector<int>> &A);
int findMedianBF(vector<vector<int>> &A);
void print(vector<vector<int>> &A)
{
    cout << "matrix:" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void print(vector<int> &A)
{
    cout << "array: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}
int main(int argc, char **argv)
{
    system("clear");

    vector<vector<int>> A{{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    print(A);
    int result = findMedianBF(A);
    cout << "matrix median bruite force: " << result << endl;
    result = findMedian(A);
    cout << "matrix median: " << result << endl;
    return 0;
}

int findMedian(vector<vector<int>> &A)
{
    int low = INT_MAX, high = INT_MIN, row = A.size(), col = A[0].size();
    for (int i = 0; i < row; i++)
    {
        low = min(low, A[i][0]);
        high = max(high, A[i][col - 1]);
    }
    int median = (row * col + 1) / 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int i = 0; i < row; i++)
        {
            int x = upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
            count += x;
        }
        if (count < median)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int findMedianBF(vector<vector<int>> &A)
{
    vector<int> arr;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            arr.push_back(A[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    print(arr);
    int size = arr.size();
    return arr[size / 2];
}
