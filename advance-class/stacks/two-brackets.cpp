#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Given two strings A and B. Each string represents an expression consisting of lowercase English alphabets, '+', '-', '(' and ')'.
 * The task is to compare them and check if they are similar. If they are identical, return 1 else, return 0.
 *
 * NOTE: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’, and every operand appears only once.
 *
 * @param A
 * @param B
 * @return int
 */
int solve(string A, string B);
vector<int> evaluate(string A);

int main(int argc, char **argv)
{
    system("clear");

    return 0;
}

int solve(string A, string B)
{
}
vector<int> evaluate(string A)
{
    stack<bool> st;
    st.push(true);

    int i = 0, len = A.length();

    vector<int> signs;

    while (i < len)
    {
        if (A[i] == '+' || A[i] == '-')
        {
            continue;
        }
        if (A[i] == '(')
        {
        }
    }
}