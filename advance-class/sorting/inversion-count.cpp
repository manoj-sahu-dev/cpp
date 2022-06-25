#include <iostream>
#include <vector>

using namespace std;

vector<int> zigZag(vector<int> &A);
vector<int> zigZag2(vector<int> &A);
int inversionCount(vector<int> &A);
int inversionCount(vector<int> &A, int start, int end);
int mergeSortInversion(vector<int> &A, int start, int mid, int end);

int countPairs(vector<int> &A, vector<int> &B);
int countPairs(vector<int> &A, vector<int> &B, int aSize, int bSize);

/**
 * @brief a simple method to print vector
 *
 * @param A vector to be printed
 * @param str optional - name of the vector
 */
void print(vector<int> &A, string str = "");
int main(int argc, char **argv)
{
    system("clear");
    /*vector<int> A{7, 3, 5};
    vector<int> B{2, 0, 6};
    int res = countPairs(A, B);
    cout << "total N2 = " << res << endl;
    res = countPairs(A, B, A.size(), B.size());
    cout << "total logN+logM = " << res << endl;*/

    // vector<int> A{10, 3, 8, 15, 6, 12, 2, 18, 7, 1};
    // int res = inversionCount(A, 0, A.size() - 1);
    // cout << "inversion count = " << res << endl;

    vector<int> A{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(A, "before");
    vector<int> B = zigZag2(A);
    print(B, "after");
    return 0;
}

vector<int> zigZag2(vector<int> &A)
{
    int n = A.size();
    bool big = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (big)
        {
            if (A[i] < A[i + 1])
                swap(A[i], A[i + 1]);
        }
        else
        {
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
        }
        big = !big;
    }
    return A;
}

vector<int> zigZag(vector<int> &A)
{
    sort(A.begin(), A.end());
    print(A, "after sorting");
    int p1 = 0, n = A.size(), p2 = n - 1;
    vector<int> B;
    while (p1 < p2)
    {
        B.push_back(A[p2]);
        B.push_back(A[p1]);
        p1 += 1;
        p2 -= 1;
    }
    if (A.size() % 2 != 0)
    {
        B.push_back(A[p1]);
    }
    return B;
}

int inversionCount(vector<int> &A, int start, int end)
{
    if (start == end)
        return 0;
    int mod = 1e9 + 7;
    int mid = (start + end) / 2;
    int x = inversionCount(A, start, mid) % mod;
    int y = inversionCount(A, mid + 1, end) % mod;
    int z = mergeSortInversion(A, start, mid, end) % mod;
    return (x + y + z) % mod;
}

int mergeSortInversion(vector<int> &A, int start, int mid, int end)
{
    vector<int> ans;
    int p1 = start, p2 = mid + 1, count = 0, mod = 1e9 + 7;
    while (p1 <= mid && p2 <= end)
    {
        if (A[p1] <= A[p2])
        {
            ans.push_back(A[p1]);
            p1 += 1;
        }
        else
        {
            ans.push_back(A[p2]);
            p2 += 1;
            count += ((mid + 1) - p1) % mod;
        }
    }
    while (p1 <= mid)
    {
        ans.push_back(A[p1]);
        p1 += 1;
    }
    while (p2 <= end)
    {
        ans.push_back(A[p2]);
        p2 += 1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        A[start + i] = ans[i];
    }
    return count % mod;
}

int inversionCount(vector<int> &A)
{
    int count = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] > A[j])
            {
                cout << "{" << A[i] << "," << A[j] << "}, ";
                count += 1;
            }
        }
        cout << endl;
    }
    return count;
}

int countPairs(vector<int> &A, vector<int> &B, int aSize, int bSize)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int p1 = 0, p2 = 0, count = 0;

    while (p1 < aSize && p2 < bSize)
    {
        if (A[p1] < B[p2])
        {
            p1 += 1;
        }
        else
        {
            count += aSize - p1;
            p2 += 1;
        }
    }
    return count;
}

int countPairs(vector<int> &A, vector<int> &B)
{
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            if (A[i] > B[j])
            {
                cout << "{" << A[i] << "," << B[j] << "}, ";
                count += 1;
            }
        }
        cout << endl;
    }
    return count;
}

void print(vector<int> &A, string str)
{
    cout << "content of vector " << str << "    ";
    for (int num : A)
        cout << num << " ";
    cout << endl;
}