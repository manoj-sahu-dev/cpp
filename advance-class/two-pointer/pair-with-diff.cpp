#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
int findPairWithDiffrence(vector<int> &A, int B)
{
    int n = A.size(), i = 0, j = n - 1;
    int pairs = 0;
    while (i < j)
    {
        cout << A[i] << " " << A[j] << ", diff = " << (A[i] + A[j]) << endl;
        if (A[i] + A[j] > B)
        {
            j--;
        }
        else if (A[i] + A[j] < B)
        {
            i++;
        }
        else
        {
            pairs += 1;
            cout << "ey" << endl;
            j -= 1;
        }
    }
    return pairs;
}
int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{1, 1, 1};
    int B = 2;
    print(A);
    int result = findPairWithDiffrence(A, B);
    cout << result << endl;
    return 0;
}