#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief merge two sorted array & return new sorted array
 * @param A First sorted array
 * @param B second sorted array
 * @return vector<int> new sorted array
 */
vector<int> mergeSortedVector(vector<int> &A, vector<int> &B);
/**
 * @brief sort vector
 * @param A vector to be sorted
 * @param left first index from where to start
 * @param right last index where to stop
 */
void sortVector(vector<int> &A, int left, int right);
/**
 * @brief sort elements of vector from indexes
 *
 * @param A vector to be sorted
 * @param left first sorting index
 * @param mid mid point, where first sorted vector stops
 * @param right second sorted index of vector
 */
void sortVectors(vector<int> &A, int left, int mid, int right);
/**
 * @brief a simple method to print vector
 *
 * @param A vector to be printed
 * @param str optional - name of the vector
 */
void print(vector<int> &A, string str = "");
int main()
{
    system("clear");
    /*vector<int> A = {1, 3, 5, 7, 9};
    vector<int> B = {2, 4, 6, 8, 10};
    vector<int> C = mergeSortedVector(A, B);
    print(A, "A");
    print(B, "B");
    print(C, "C");*/
    vector<int> A{3, 2, 5, 1, 7, 4, 9, 8, 6};
    print(A, "A");
    // sortVectors(A, 1, 4, 7);
    // print(A, "after sort");
    sortVector(A, 0, A.size() - 1);
    print(A, "after sort");

    return 0;
}

void sortVector(vector<int> &A, int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    sortVector(A, left, mid);
    sortVector(A, mid + 1, right);
    sortVectors(A, left, mid, right);
}

void sortVectors(vector<int> &A, int left, int mid, int right)
{
    vector<int> ans;
    int p1 = left, p2 = mid + 1;
    // cout << "p1 = " << p1 << " p2 = " << p2 << ", mid = " << mid << ", right = " << right << endl;
    while (p1 <= mid && p2 <= right)
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
        }
    }

    while (p1 <= mid)
    {
        ans.push_back(A[p1]);
        p1 += 1;
    }
    while (p2 <= right)
    {
        ans.push_back(A[p2]);
        p2 += 1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        A[left + i] = ans[i];
    }
}

vector<int> mergeSortedVector(vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    int p1 = 0, p2 = 0, n1 = A.size(), n2 = B.size();

    while (p1 < n1 && p2 < n2)
    {
        if (A[p1] < B[p2])
        {
            ans.push_back(A[p1]);
            p1 += 1;
        }
        else
        {
            ans.push_back(B[p2]);
            p2 += 1;
        }
    }
    while (p1 < n1)
    {
        ans.push_back(A[p1]);
        p1 += 1;
    }

    while (p2 < n2)
    {
        ans.push_back(B[p2]);
        p2 += 1;
    }

    return ans;
}

void print(vector<int> &A, string str)
{
    cout << "content of vector " << str << "    ";
    for (int num : A)
        cout << num << " ";
    cout << endl;
}