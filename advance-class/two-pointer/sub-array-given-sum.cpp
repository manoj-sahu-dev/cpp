#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

vector<int> findSubArraySum(vector<int> &A, int target);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{1, 2, 3, 4, 5};
    int B = 5;
    print(A);
    vector<int> result = findSubArraySum(A, B);
    print(result);

    return 0;
}

vector<int> findSubArraySum(vector<int> &A, int target)
{
    int i = 0, n = A.size(), j = 0, currentSum = 0;

    while (j < n)
    {
        currentSum += A[j];
        cout << "current sum: " << currentSum << endl;
        while (i <= j && currentSum > target)
        {
            cout << "A[" << i << "] = " << A[i] << ", current sum = " << currentSum << endl;
            currentSum -= A[i];
            i++;
        }

        if (currentSum == target)
        {
            return {i, j};
        }
        j++;
    }
    return {-1};
}