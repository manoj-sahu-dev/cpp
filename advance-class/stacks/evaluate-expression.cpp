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
bool isOperand(string A);
int evalRPN(vector<string> &A);
int main(int argc, char **argv)
{
    system("clear");
    vector<string> A{"2", "1", "+", "3", "*"};
    int res = evalRPN(A);
    cout << "result: " << res << endl;
    return 0;
}

bool isOperand(string A)
{
    if (A == "+" || A == "-" || A == "*" || A == "/")
        return false;
    return true;
}

int evalRPN(vector<string> &A)
{
    stack<string> temp;
    int result = 0;
    for (int i = 0; i < A.size(); i++)
    {
        string s = A[i];
        if (isOperand(s))
        {
        }
        else
        {
        }
    }
    return result;
}