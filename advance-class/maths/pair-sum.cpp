#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Given an array of integers A and an integer B, find and return the number of pairs in A whose sum is divisible by B.
 * Since the answer may be large, return the answer modulo (109 + 7).
 * @param A
 * @param B
 * @return int
 */
int findPairSum(vector<int> &A, int B);

void print(vector<int> &A)
{
    cout << "content: ";
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}
int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{1, 2, 3, 4, 5};
    int B = 2;

    int result = findPairSum(A, B);

    cout << "total pairs: " << result << endl;

    return 0;
}

int findPairSum(vector<int> &A, int B)
{
    int pairs = 0;
    // bruit force
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            cout << A[i]
        }
    }
    return pairs;
}