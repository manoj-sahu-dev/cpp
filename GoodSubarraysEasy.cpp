#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> &A);
int FindGoodSubArray(vector<int> &A, int B);
int main()
{
    vector<int> A{12, 10, 9, 17, 8, 17, 16, 16, 7, 17, 3, 14, 1, 19, 7, 19, 5, 11, 3};
    PrintVector(A);
    int result = FindGoodSubArray(A, 210);
    cout << endl
         << "good sub array = " << result << endl;
    return 0;
}
int FindGoodSubArray(vector<int> &A, int B)
{
    int count = 0, n = A.size();
    for (int i = 1; i < n; i++)
        A[i] += A[i - 1];
    for (int sp = 0; sp < n; sp++)
    {
        int sum = 0;
        for (int ep = sp; ep < n; ep++)
        {
            sum = A[ep] - (sp == 0 ? 0 : A[sp - 1]);
            if ((sum < B && ((ep - sp) + 1) % 2 == 0) || (sum > B && ((ep - sp) + 1) % 2 != 0))
            {
                count += 1;
            }
        }
    }
    return count;
}
void PrintVector(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}