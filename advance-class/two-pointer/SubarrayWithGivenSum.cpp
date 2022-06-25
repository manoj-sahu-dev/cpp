#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
vector<int> getSubArrayWithGivenSum(vector<int> &A, int B)
{
    int i = 0, j = 0, n = A.size(), sum = 0;

    while (j < n)
    {
        sum += A[j];
        j += 1;

        while (sum > B && i < j)
        {
            sum -= A[i];
            i++;
        }
        if (sum == B)
        {
            cout << "i = " << A[i] << ", j = " << A[j - 1] << endl;
            vector<int> res;
            for (int m = i; m < j; m++)
            {
                res.push_back(A[m]);
            }
            return res;
        }
    }
    return {-1};
}

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{1, 2, 3, 4, 5};
    int B = 5;
    print(A);
    vector<int> result = getSubArrayWithGivenSum(A, B);
    print(result);
    return 0;
}