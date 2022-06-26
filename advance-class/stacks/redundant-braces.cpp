#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.
 * Check whether A has redundant braces or not.
 * NOTE: A will be always a valid expression and will not contain any white spaces.
 * @param A
 * @return int
 */
int braces(string A);

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main(int argc, char **argv)
{
    system("clear");
    string A;
    cout << "enter a string : ";
    cin >> A;
    int result = braces(A);
    cout << "result : " << result << endl;
    return 0;
}

int braces(string A)
{
    int len = A.length();
    stack<char> operators;
    for (int i = 0; i < len; i++)
    {
        char ch = A[i];
        if (ch >= 'a' && ch <= 'z')
        {
            continue;
        }

        if (ch == '(' || isOperator(ch))
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            if (!operators.empty() && operators.top() == '(')
            {
                operators.pop();
                return true;
            }

            while (!operators.empty() && operators.top() != '(')
            {
                operators.pop();
            }
            operators.pop();
        }
    }
    return false;
}
