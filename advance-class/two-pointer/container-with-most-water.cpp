#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

vector<int> findContainerWithMostWanter(vector<int> &A);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{1, 5, 4, 3};
    print(A);
    vector<int> result = findContainerWithMostWanter(A);
    print(result);

    return 0;
}

vector<int> findContainerWithMostWanter(vector<int> &A)
{
    int i = 0, n = A.size(), j = n - 1, res = 0;
    vector<int> result = {};

    while (i < j)
    {
        int area = j - i;
        int height = min(A[j], A[i]);
        int volume = area * height;

        int temp = max(res, volume);
        if (temp > res)
        {
            res = temp;
            result = {A[i], A[j]};
        }

        if (A[i] < A[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "res = " << res << endl;
    return result;
}