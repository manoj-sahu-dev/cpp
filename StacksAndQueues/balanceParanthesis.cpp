#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

int isBalanced(string A);
void print(stack<char> &A);

int main()
{
    system("clear");
    string A;
    cin >> A;
    cout << "is balanced: " << isBalanced(A) << endl;
    return 0;
}

int isBalanced(string A)
{
    stack<char> ms;
    int len = A.length(), left = 0;
    while (left < len)
    {
        char ch = A[left];
        cout << "\nchar is : " << ch << " " << endl;
        if (ch == '[' || ch == '{' || ch == '(')
        {
            ms.push(A[left]);
        }
        else if (ch == ']' || ch == '}' || ch == ')')
        {
            cout << "\n else part\n";
            if (ms.empty())
            {
                return false;
            }
            char temp = ms.top();
            if (ch == ')' && temp != '(')
            {
                return false;
            }
            else if (ch == '}' && temp != '{')
            {
                return false;
            }
            else if (ch == ']' && temp != '[')
            {
                return false;
            }
            cout << "popping" << ch << ", " << temp << endl;
            ms.pop();
        }
        left += 1;
    }
    print(ms);
    return (ms.size() > 0);
}
void print(stack<char> &A)
{
    cout << "stack: \n";
    while (A.size() > 0)
    {
        cout << A.top() << ", " << A.size() << endl;
        A.pop();
    }
}