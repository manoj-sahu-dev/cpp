#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Given string A denoting an infix expression. Convert the infix expression into a postfix expression.
 * String A consists of ^, /, *, +, -, (, ) and lowercase English alphabets where lowercase English alphabets are operands and ^, /, *, +, - are operators.
 * Find and return the postfix expression of A.
 *
 * NOTE:
 * ^ has the highest precedence.
 * / and * have equal precedence but greater than + and -.
 * + and - have equal precedence and lowest precedence among given operators.
 *
 * @param A
 * @return string
 */
string solve(string A);

bool is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

bool has_equal_or_higher_precedence(char a, char b)
{
    if (a == '^')
    {
        return (b == '+' || b == '-' || b == '*' || b == '/' || b == '^');
    }
    if (a == '*' || a == '/')
    {
        return (b == '+' || b == '-' || b == '*' || b == '/');
    }
    if (a == '+' || a == '-')
    {
        return (b == '+' || b == '-');
    }
    return false;
}

int main(int argc, char **argv)
{
    system("clear");
    string A = "x^y/(a*z)+b";
    cout << "enter a string: ";
    cin >> A;
    string result = solve(A);
    cout << "result: " << result << endl;

    return 0;
}

string solve(string A)
{
    stack<char> operators;
    int len = A.size();
    string ans;
    for (int i = 0; i < len; i++)
    {
        char ch = A[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ans += ch;
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            while (operators.top() != '(')
            {
                ans += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            while (!operators.empty() && has_equal_or_higher_precedence(operators.top(), ch))
            {
                char top = operators.top();
                ans += top;
                operators.pop();
            }
            operators.push(ch);
        }
    }
    while (!operators.empty())
    {
        ans += operators.top();
        operators.pop();
    }
    return ans;
}
