#include <iostream>
#include <vector>
#include <stack>
#include <pai

using namespace std;

void push(int x);
void pop();
int top();
int getMin();

stack<pair<int, int> > stacks;

int main()
{
    getMin();
    top();
    top();
    getMin();

    push(593848644);
    return 0;
}

int solve(int A, int B)
{

    if (A == 1 || B == 1)
    {
        return 0;
    }

    int sol = solve(A - 1, (B + 1) / 2);

    if (sol == 0)
    {
        return (B & 1) == 1 ? 0 : 1;
    }
    else
    {
        return (B & 1) == 1 ? 1 : 0;
    }
}
void push(int x)
{

    {
        cout << "Empty stack" << endl;
        stacks.push({x, x});
        return;
    }

    int currentMin = stacks.top()[1];
    cout << currentMin << endl;
    stacks.push({x, min(x, currentMin)});
}

void pop()
{
    if (stacks.empty())
    {
        return;
    }
    stacks.pop();
}

int top()
{
    if (stacks.empty())
    {
        cout << "top: empty stack" << endl;
        return -1;
    }
    return stacks.top()[0];
}

int getMin()
{
    if (stacks.empty())
    {
        cout << "getMin: empty stack" << endl;
        return -1;
    }
    return stacks.top()[1];
}