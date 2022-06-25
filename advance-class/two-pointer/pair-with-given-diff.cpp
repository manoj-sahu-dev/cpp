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

    vector<int> A{1, 1, 1};
    int B = 2;
    print(A);
    int result = findPairs(A, B);
    cout << result << endl;

    return 0;
}

int findPairs(vector<int> &A, int B)
{
    int pairs = 0, i = 0, j = 1, n = A.size();

    // for (i = 0; i < n - 1; i++) // bruite force
    // {
    //     for (j = i + 1; j < n; j++)
    //     {
    //         pairs += 1;
    //     }
    // }
    return pairs;
    while (i < n - 1)
    {
        int cs = A[i] + A[j];
        if (cs == B)
        {
            if (A[i] == A[j])
            {
            }
        }
        else if (cs < B)
        {
            i += 1;
        }
        else if (cs > B)
        {
            j += 1;
        }
    }
    return pairs;
}