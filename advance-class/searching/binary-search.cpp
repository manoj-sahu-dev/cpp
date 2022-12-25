#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << i << " : " << A[i] << ",  ";

    cout << endl;
}
void print(vector<vector<int>> &A)
{
    int rows = A.size();
    int columns = A[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
void towerOfHanoiRec(int n, vector<vector<int>> &res, int first, int helper, int last)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoiRec(n - 1, res, first, last, helper);
    vector<int> temp;
    temp.push_back(n);
    temp.push_back(first);
    temp.push_back(last);
    res.push_back(temp);
    towerOfHanoiRec(n - 1, res, helper, first, last);
}

vector<vector<int>> Solution::towerOfHanoi(int A)
{
    vector<vector<int>> res;
    towerOfHanoiRec(A, res, 1, 2, 3);
    return res;
}

int binarySearch(vector<int> &A, int element);
int findFloor(vector<int> &A, int target);
int findFirstOccurence(vector<int> &A, int target);
int findPeakElement(vector<int> &A, int target);
int findTargetInRotatedVector(vector<int> &A, int target);
vector<int> searchMatrix(vector<vector<int>> &A, int B);
int findOddElement(vector<int> &A);
int sqrt(int A);
int main(int argc, char **argv)
{
    system("clear");
    /*vector<int> A{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(A);
    int result = binarySearch(A, 5);
    cout << "index: " << result << endl;*/

    /* vector<int> A{-5, 2, 3, 6, 9, 10, 11, 14, 18};
    print(A);
    int target = 0;
    cout << "enter position: ";
    cin >> target;
    int result = findFloor(A, target);
    cout << "index: " << result << endl; */

    /*vector<int> A{101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100};
    print(A);
    int target = 0;
    cout << "enter target: ";
    cin >> target;
    int result = findTargetInRotatedVector(A, target);
    cout << "index: " << result << endl;*/
    /*vector<vector<int> > A{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    print(A);
    int target = 0;
    cout << "\nenter a num to find in matrix: ";
    cin >> target;
    vector<int> result = searchMatrix(A, target);*/
    /*vector<int> A{2, 2, 3, 3, 4, 4, 6, 6, 7, 7, 8, 8, 9, 9, 10};
    print(A);
    int result = findOddElement(A);
    cout << result << endl;*/
    for (int i = 0; i < 10; i++)
        cout << "i = " << i << ", " << sqrt(i) << endl;
    return 0;
}

int sqrt(int A)
{
    int low = 1, high = A;
    int mid = (low + high) / 2;
    int ans = mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        // cout << "\n -> low = " << low << ", high = " << high << ", mid = " << mid << endl;
        if (mid * mid == A)
        {
            return mid;
        }
        else if (mid * mid < A)
        {
            ans = low;
            low = mid + 1;
        }
        else if (mid * mid > A)
        {
            high = mid - 1;
        }
        // cout << "\n --> low = " << low << ", high = " << high << ", mid = " << mid << endl;
    }
    return ans;
    // h = 10
    // l= 1, m = 5, h = 11
    // l = 1, h = 4, m = 2
    //
}

int findOddElement(vector<int> &A)
{
    int xo = A[0];
    for (int i = 1; i < A.size() - 1; i++)
    {
        // xo = A[i] ^ xo;
        if (A[i] != A[i - 1] || A[i] != A[i + 1])
        {
            return A[i];
        }
    }
    return xo;
}

vector<int> searchMatrix(vector<vector<int>> &A, int B)
{
    int i = 0;
    int j = A[0].length - 1;
    while (i <= A.length - 1 && j >= 0)
    {
        if (A[i][j] == B)
        {
            return 1;
        }
        else if (A[i][j] > B)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
    int rows = A.size(), columns = A[0].size(), low = 0, mid = 0, high = (rows * columns) - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int i = mid / rows;
        int j = mid % rows;
        if (A[i][j] == B)
        {
            return {i, j};
        }
        else if (A[i][j] < B)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return {-1, -1};
}

int findTargetInRotatedVector(vector<int> &A, int B)
{
    int low = 0, mid = 0, n = A.size(), high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (A[mid] == B)
        {
            return mid;
        }
        else if (A[0] < A[mid]) // search left subarray
        {
            if (A[0] <= B && B < A[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else // search right subarray
        {
            if (A[mid] < B && B <= A[n - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int findPeakElement(vector<int> &A)
{
    int low = 0, high = A.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (A[mid] < A[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return A[low];
}

int findFirstOccurence(vector<int> &A, int target)
{
    int low = 0, n = A.size(), mid = 0, high = n - 1, pi = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == target)
        {
            pi = mid;
            high = mid - 1;
            cout << "->";
        }
        else if (A[mid] > target)
        {
            high = mid - 1;

            cout << "-->";
        }
        else
        {
            low = mid + 1;

            cout << "--->";
        }
        cout << "target: " << target << ", mid: " << mid << ", low: " << low << ", high: " << high << ", pi: " << pi << endl;
    }
    return pi;
}

int findFloor(vector<int> &A, int target)
{
    int low = 0, n = A.size(), high = n - 1, mid = 0, pa = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (target == A[mid])
        {
            return A[mid];
        }
        else if (target < A[mid])
        {
            high = mid - 1;
            pa = A[high];
        }
        else
        {
            low = mid + 1;
        }
    }
    return pa;
}

int binarySearch(vector<int> &A, int element)
{
    int left = 0, n = A.size(), right = n - 1, mid = 0;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] == element)
        {
            return mid;
        }
        else if (A[mid] > element)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}