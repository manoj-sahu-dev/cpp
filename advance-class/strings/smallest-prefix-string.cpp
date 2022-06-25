#include <iostream>

using namespace std;
string solve(string A, string B);
int main(int argc, char **argv)
{
    system("clear");
    string A = "harry";
    string B = "potter";
    string result = solve(A, B);
    cout << "result: " << result << endl;
    return 0;
}
string solve(string A, string B)
{

    int alen = A.length(), blen = B.length(), j = 0;
    string ans = "";

    ans += A[0]; // ans will always have first character from string A

    for (int i = 1; i < alen; i++) // run loop throught string A len
    {
        cout << A[i] << " : " << B[j] << " : " << (A[i] < B[j]) << endl;
        if (A[i] < B[j]) // if character at given index is smaller than j index at B string, append first to ans string
        {
            ans += A[i];
        }
        else if (A[i] > B[j]) // if character at given index is larger than j index at B string, append first to ans string
        {
            ans += B[j];
            j += 1;
            break;
        }
        else // both are equal, we found one to be inserted from B
        {
            ans += B[j];
            j += 1;
            break;
        }
    }
    // cout << j << endl;
    while (j < 1) // just in case, if nothing was included from B, time to add it
    {
        ans += B[j];
        j += 1;
    }
    return ans;
}