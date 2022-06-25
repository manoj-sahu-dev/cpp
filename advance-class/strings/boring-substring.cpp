#include <iostream>

using namespace std;

/**
 * @brief You are given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there is no boring substring in A.
 *
 * A boring substring has the following properties:
 * Its length is 2.
 * Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.(If the first character is C then the next character can be either (C+1) or (C-1)).
 * Return 1 if it is possible to rearrange the letters of A such that there are no boring substrings in A else, return 0.
 *
 * @param A
 * @return 0 or 1
 */
int checkBoaring(string &A);

void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l, r - 1);

            // backtrack
            swap(a[l], a[i]);
        }
    }
}
int main(int argc, char **argv)
{
    system("clear");
    string A = "abcd";
    // permute(A, 0, A.length() - 1);
    int isBoring = checkBoaring(A);
    cout << "string is boring: " << isBoring << endl;
    return 0;
}

int checkBoaring(string &A)
{
    int n = A.length();

    string odd, even;

    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            even += A[i];
        }
        else
        {
            odd += A[i];
        }
    }
    cout << "odd : " << odd << endl;
    cout << "even : " << even << endl;
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    cout << "odd : " << odd << endl;
    cout << "even : " << even << endl;

    if (abs(odd[odd.length() - 1] - even[0]) != 1)
    {
        return 1;
    }
    if (abs(even[even.length() - 1] - odd[0]) != 1)
    {
        return 1;
    }
    return 0;
}