#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Given an expression string A, examine whether the pairs and the orders of “{“,”}”, ”(“,”)”, ”[“,”]” are correct in A.
 *
 * @param A
 * @return int
 */
int solve(string A);

int main(int argc, char **argv)
{
    system("clear");
    string A = "";
    cout << "enter a string: ";
    cin >> A;
    int ans = solve(A);
    cout << "answer: " << ans << endl;
    return 0;
}

int solve(string A)
{
    int i = 0, n = A.length();
    stack<char> ps;
    while (i < n) // {[[}[]}(]}){
    {
        char ch = A[i];
        cout << ch << endl;
        if (ch == '(' || ch == '{' || ch == '[')
        {
            ps.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (ps.empty())
                return 0;

            char pop = ps.top();
            cout << "-> " << pop << ", " << ch << endl;
            if (ch == ')' && pop != '(')
                return 0;
            if (ch == '}' && pop != '{')
                return 0;
            if (ch == ']' && pop != '[')
                return 0;
            ps.pop();
        }
        i += 1;
    }

    return ps.size() == 0;
}