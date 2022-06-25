#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

int findPairs(vector<int> &A, int B);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{1, 2, 6, 6, 7, 9, 9};
    int B = 13;
    print(A);
    int result = findPairs(A, B);
    cout << result << endl;

    return 0;
}

int findPairs(vector<int> &A, int B)
{
    int pairs = 0, n = A.size(), i = 0, j = n - 1;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if ((A[i] + A[j]) == B)
    //         {
    //             pairs += 1;
    //             cout << " i = " << i << ", j = " << j << ", pairs = " << pairs << endl;
    //         }
    //     }
    // }
    while (i < j)
    {
        int sum = A[i] + A[j];
        if (sum > B)
        {
            j -= 1;
        }
        else if (sum < B)
        {
            i += 1;
        }
        else
        {
            pairs += 1;
            i += 1;
            j -= 1;
        }
        cout << "i = " << i << ", j = " << j << ", B = " << B << ", sum = " << sum << ", pairs = " << pairs << endl;
    }

    return pairs;
}