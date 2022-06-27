#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief An arithmetic expression is given by a character array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each character may be an integer or an operator.
 *
 * @param A
 * @return int
 */
int evalRPN(vector<string> &A);
bool isOperator(string s);
int getResult(string op, int first, int second);

int main(int argc, char **argv)
{
    system("clear");
    vector<string> A{"4"};
    int result = evalRPN(A);
    cout << result << endl;
    return 0;
}

bool isOperator(string s)
{
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int getResult(string op, int first, int second)
{
    int ans = 0;
    if (op == "+")
    {
        ans = first + second;
    }
    else if (op == "-")
    {
        ans = first - second;
    }
    else if (op == "*")
    {
        ans = first * second;
    }
    else if (op == "/")
    {
        ans = first / second;
    }
    cout << "op: " << op << ", first: " << first << ", second: " << second << ", ans: " << ans << endl;
    return ans;
}

int evalRPN(vector<string> &A)
{
    stack<int> st;
    int len = A.size();
    int result = 0;
    for (auto s : A)
    {
        cout << "s : " << s << ", isOperator : " << isOperator(s) << endl;
        if (isOperator(s))
        {
            int second = st.top();
            st.pop();
            if (!st.empty()) //"5", "1", "2", "+", "4", "*", "+", "3", "-"
            {
                int first = st.top();
                st.pop();
                result = getResult(s, first, second);
                st.push(result);
            }
            else
            {
                result = getResult(s, second, result);
            }
        }
        else
        {
            st.push(stoi(s));
        }
        cout << "st: " << st.size() << endl;
    }
    if (!st.empty())
        return st.top();
    return result;
}
