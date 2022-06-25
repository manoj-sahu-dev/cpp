#include <iostream>
#include <vector>

using namespace std;
/*
 given an array A, reaarange the array such that A[0] should go to its sorted position in
 all elements <= A[0] should go left, and >A[0] should go to right
 A = [10, 3, 8, 15, 6, 12, 2, 18, 7, 15, 14]
 result - A = [3, 8, 6, 2, 7, 10, 15, 12, 18, 15, 14]
 sorting takes NlogN time
*/

vector<int> reArrange(vector<int> &A);
vector<int> reArrange2(vector<int> &A);

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

    vector<int> A{10, 3, 8, 15, 6, 12, 2, 18, 7, 15, 14};
    print(A, "before");
    vector<int> result = reArrange(A);
    print(result, "after");
    return 0;
}
vector<int> reArrange(vector<int> &A)
{
    int p1 = 1, n = A.size(), p2 = n - 1;

    while (p1 <= p2)
    {
        if (A[p1] <= A[0])
        {
            p1 += 1;
        }
        else if (A[p2] > A[0])
        {
            p2 -= 1;
        }
        else
        {
            swap(A[p1], A[p2]);
        }
    }
    swap(A[0], A[p2]);
    return A;
}

vector<int> reArrange2(vector<int> &A)
{
    vector<int> result(A.size());
    int p1 = 0, n = A.size(), p2 = n - 1;

    for (int i = 1; i < n; i++)
    {
        if (A[i] <= A[0])
        {
            result[p1] = A[i];
            p1 += 1;
        }
        else
        {
            result[p2] = A[i];
            p2 -= 1;
        }
    }
    result[p2] = A[0];
    return result;
}

void print(vector<int> &A, string str)
{
    cout << "content of vector " << str << "    ";
    for (int num : A)
        cout << num << " ";
    cout << endl;
}