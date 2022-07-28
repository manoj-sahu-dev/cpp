#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Given 2 integers A and B and an array of integers C of size N. Element C[i] represents the length of ith board.
 * You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of the board.
 *
 * Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of the board.
 * NOTE:
 * 1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
 * 2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.
 *
 * Return the ans % 10000003.
 *
 * @param A Number of painters
 * @param B Number of walls each painter can paint
 * @param C
 * @return int
 */
int paint(int A, int B, vector<int> &C);
bool is_possible(int A, int B, vector<int> &C, int mid);
int main(int argc, char **argv)
{
    system("clear");
    int A = 10;
    int B = 2;
    vector<int> C{1, 8, 11, 3};
    int ans = paint(A, B, C);
    cout << "answer = " << ans << endl;
    return 0;
}

bool is_possible(int A, int B, vector<int> &C, int mid)
{
    return true;
}

int paint(int A, int B, vector<int> &C)
{
    int ans = -1, left = 0, right = 0, mid = 0, n = C.size(), mod_value = 10000003;
    for (int i = 0; i < n; i++)
    {
        left = max(C[i], left);
        right += C[i];
    }
    cout << "search space: left = " << left << ", right = " << right << endl;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        cout << "---   mid = " << mid << "  ---" << endl;
        if (is_possible(A, B, C, mid))
        {
            ans = mid % mod_value;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans % mod_value;
}
