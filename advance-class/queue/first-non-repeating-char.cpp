#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * @brief Given a string A denoting a stream of lowercase alphabets, you have to make a new string B.
 * B is formed such that we have to find the first non-repeating character each time a character is inserted to the stream and append it at the end to B.
 * If no non-repeating character is found, append '#' at the end of B.
 *
 * @param A
 * @return string
 */
string solve(string A);

int main(int argc, char **argv)
{
    system("clear");
    string A = "abcabc";
    string ans = solve(A);
    cout << "ans = " << ans << endl;
    return 0;
}

string solve(string A)
{
    queue<char> q;
    unordered_map<char, int> count;
    string ans = "";
    for (int i = 0; i < A.size(); i++)
    {
        char c = A[i];
        count[c] += 1;
        cout << "c = " << c << ", cout  = " << count[c] << endl;
        q.push(c);

        while (!q.empty())
        {
            cout << "inside queue: " << q.front() << endl;
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans += q.front();
                break;
            }
        }
        if (q.empty())
            ans += "#";
    }
    return ans;
}
