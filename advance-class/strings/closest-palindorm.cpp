#include <iostream>

using namespace std;

/**
 * @brief Groot has a profound love for palindrome which is why he keeps fooling around with strings.
 * A palindrome string is one that reads the same backward as well as forward.
 * Given a string A of size N consisting of lowercase alphabets, he wants to know if it is possible to make the given string a palindrome by changing exactly one of its character.
 * @param A string
 * @return string "YES" or "NO"
 */
string solve(string A);

int main()
{
    system("clear");
    string A;
    cout << "enter a string: ";
    cin >> A;
    string ans = solve(A);
    cout << "string can be changed to palindrome by chaning 1 " << ans << endl;
    return 0;
}

string solve(string A)
{
    int n = A.length(), i = 0, j = n - 1, count = 0;

    while (i <= j)
    {
        if (A[i] != A[j])
        {
            count += 1;
        }
        i += 1;
        j -= 1;
    }
    cout << "count = " << count << endl;
    if (count == 1)
    {
        return "YES";
    }
    if (count == 0)
    {
        if (n % 2 == 1)
            return "YES";
    }
    return "NO";
}