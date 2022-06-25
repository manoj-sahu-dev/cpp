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
 * @brief Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].
 * Return the number of important reverse pairs in the given array A.
 *
 * @param A
 * @return int
 */
int reversePairs(vector<int> &A);

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{1, 3, 2, 3, 1};
    print(A);
    int result = reversePairs(A);
    cout << "total reverse pairs : " << result << endl;
    return 0;
}
int reversePairs(vector<int> &A)
{
    int count = 0, i = 1, n = A.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > (2 * A[j]))
            {
                cout << "[" << i << ", " << j << "]" << endl;
                count += 1;
            }
        }
    }
    return count;
}