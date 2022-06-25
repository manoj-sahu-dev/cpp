#include <iostream>
#include <vector>
#include <string>

using namespace std;
void print(vector<int> &A)
{
    cout << "content of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}
vector<int> findLPS(const string &A)
{
    int i = 0, j = 1, n = A.length();
    vector<int> lps(n, 0);

    while (j < n)
    {
        if (A[i] == A[j])
        {
            i++;
            lps[j] = i;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = lps[i - 1];
            }
            else
            {
                lps[j] = 0;
                j += 1;
            }
        }
    }
    return lps;
}
int findMinimalCharToPalindrome(string A)
{
    string reversedString = A;
    reverse(reversedString.begin(), reversedString.end());
    string nString = A + "$" + reversedString;
    vector<int> lps = findLPS(nString);
    print(lps);
    return (A.length() - lps.back());
}
int main(int argc, char **argv)
{
    system("clear");
    string A = "dsgwadsgz";
    cout << "enter a string: ";
    cin >> A;
    int result = findMinimalCharToPalindrome(A);
    cout << "result = " << result << endl;
    return 0;
}