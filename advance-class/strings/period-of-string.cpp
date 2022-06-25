#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    cout << "content of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

/**
 * @brief You are given a string A of length N consisting of lowercase alphabets. Find the period of the string.
 * Period of the string is the minimum value of k (k >= 1), that satisfies A[i] = A[i % k] for all valid i.
 *
 * @param A
 * @return vector<int>
 */
vector<int> generateLPS(string A)
{
    int n = A.length(), i = 0, j = 1;
    vector<int> lps(n, 0);

    while (j < n)
    {
        if (A[i] == A[j])
        {
            i += 1;
            lps[j] = i;
            j += 1;
        }
        else
        {
            if (i == 0)
            {
                lps[j] = i;
                j += 1;
            }
            else
            {
                i = lps[j];
            }
        }
    }
    return lps;
}

int main()
{
    system("clear");

    string A = "abababab";
    cout << "enter a string: ";
    cin >> A;
    vector<int> lps = generateLPS(A);
    print(lps);

    int n = A.length();

    int ans = n - lps[n - 1];
    cout << "ans = " << ans << endl;
    return 0;
}