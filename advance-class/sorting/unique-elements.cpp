#include <iostream>
#include <vector>

using namespace std;
enum Direction
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

void print(vector<int> &A)
{
    cout << "\ncontent of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

/**
 * @brief You are given an array A of N elements. You have to make all elements unique. To do so, in one step you can increase any number by one.
 * Find the minimum number of steps.
 *
 * @param A vector of N elements of type int
 * @return int
 */
int getStepsToMakeUnique(vector<int> &A);

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{2, 4, 3, 4, 5, 3};
    print(A);
    int result = getStepsToMakeUnique(A);
    cout << "total counts: " << result << endl;
    return 0;
}
int getStepsToMakeUnique(vector<int> &A)
{
    int count = 0, i = 1, n = A.size();
    sort(A.begin(), A.end());
    print(A);

    while (i < n)
    {
        if (A[i] == A[i - 1])
        {
            A[i] = A[i] + 1;
            count++;
        }
        else if (A[i] < A[i - 1])
        {
            while (A[i] <= A[i - 1])
            {
                A[i] += 1;
                count++;
            }
        }
        i += 1;
    }
    print(A);
    return count;
}