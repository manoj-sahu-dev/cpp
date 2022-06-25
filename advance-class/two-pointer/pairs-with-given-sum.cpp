#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
int pairsWithGivenSum(vector<int> &A, int B);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{2, 2, 3, 4, 4, 5, 6, 7, 10};
    print(A);
    int B = 8;
    int result = pairsWithGivenSum(A, B);
    cout << "result: " << result << endl;
    return 0;
}

int pairsWithGivenSum(vector<int> &A, int B)
{
    int n = A.size(), count = 0, i = 0, j = n - 1, mod = 1000000007;
    // for (int i = 0; i < n - 1; i++)
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (A[i] + A[j] == B)
    //             count++;
    //     }
    // return count;
    while (i < j)
    {
        int sum = A[i] + A[j];
        cout << "i = " << i << ", j = " << j << ", " << A[i] << ", " << A[j] << ", sum = " << sum << endl;
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
            cout << " --- > " << A[i] << " : " << A[j] << endl;
            if (A[i] == A[j])
            {
                int x = j - i + 1;
                cout << ", x = " << x << endl;
                count += (x * (x - 1) / 2) % mod;
                break;
            }
            else
            {
                int a = 1, b = 1, temp = A[i];
                while (A[++i] == temp)
                {
                    a += 1;
                }
                temp = A[j];
                while (A[--j] == temp)
                {
                    b += 1;
                }
                count += (a * b) % mod;
            }
        }
    }
    return count;
}