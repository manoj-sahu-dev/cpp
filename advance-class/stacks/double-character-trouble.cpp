#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief You are given a string A.
 * An operation on the string is defined as follows:
 * Remove the first occurrence of the same consecutive characters. eg for a string "abbcd", the first occurrence of same consecutive characters is "bb".
 * Therefore the string after this operation will be "acd".
 * Keep performing this operation on the string until there are no more occurrences of the same consecutive characters and return the final string.
 *
 * @param A
 * @return string
 */
string solve(string A);

int main(int argc, char **argv)
{
    system("clear");
    string A = "";
    cout << "enter a string: ";
    cin >> A;
    string ans = solve(A);
    cout << "answer: " << ans << endl;
    return 0;
}

string solve(string A)
{
    int start = 0, end = A.length();
    stack<char> ms;

    while (start < end)
    {
        char ch = A[start];
        if (ms.empty())
        {
            ms.push(ch);
        }
        else
        {
            char sc = ms.top();
            if (ch != sc)
            {
                ms.push(ch);
            }
            else
            {
                ms.pop();
            }
        }
        start += 1;
    }
    string ans = "";
    while (!ms.empty())
    {
        char ch = ms.top();
        ans += ch;
        ms.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}