#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

int findDistinctPairs(vector<int> &A);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{8, 12, 16, 4, 0, 20};
    print(A);
    int result = findDistinctPairs(A);
    cout << result << endl;

    return 0;
}
int findDistinctPairs(vector<int> &A)
{
    int i = 0, j = 1, n = A.size(), count = 0, pair2 = -1, pair1 = -1;
    sort(A.begin(), A.end());
    while (j < n)
    {
        int diff = abs(A[j] - A[i]);
        if (diff == B)
        {
            if (pair1 != A[j] && pair2 != A[i])
            {
                count++;
                pair1 = A[j];
                pair2 = A[i];
            }

            i++, j++;
        }
        else if (diff > B)
        {
            i++;
            if (i == j)
            {
                j++;
            }
        }
        else
        {
            j++;
        }
    }
    return count;
}