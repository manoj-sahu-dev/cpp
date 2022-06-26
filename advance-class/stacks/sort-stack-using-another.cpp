#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> sortStack(stack<int> &A);
stack<int> mergeStack(stack<int> &A, stack<int> &B);

/**
 * @brief Given a stack of integers A, sort it using another stack.
 * Return the array of integers after sorting the stack using another stack.
 *
 * @param A
 * @return vector<int>
 */
vector<int> solve(vector<int> &A);

void print(vector<int> &A, string message = "")
{
    cout << message << " content of vector: ";
    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}
void print(stack<int> A, string message = "")
{
    cout << message << " content of stack: ";
    while (!A.empty())
    {
        cout << A.top() << " ";
        A.pop();
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{5, 17, 100, 11};
    print(A, "origional");
    A = solve(A);
    print(A, "sorted");
    return 0;
}
vector<int> solve(vector<int> &A)
{
    stack<int> stackA;
    for (auto x : A)
    {
        stackA.push(x);
    }
    stack<int> sorted = sortStack(stackA);
    print(sorted, "sorted");
    vector<int> temp;
    while (!sorted.empty())
    {
        temp.push_back(sorted.top());
        sorted.pop();
    }
    return temp;
}

stack<int> sortStack(stack<int> &A)
{
    if (A.size() <= 1)
        return A;

    stack<int> B;
    int mid = A.size() / 2;
    for (int i = 0; i < mid; i++)
    {
        B.push(A.top());
        A.pop();
    }
    stack<int> A1 = sortStack(A);
    stack<int> B1 = sortStack(B);
    return mergeStack(A1, B1);
}

stack<int> mergeStack(stack<int> &A, stack<int> &B)
{
    if (A.empty())
        return B;
    if (B.empty())
        return A;
    cout << "\n\n";
    print(A, "merge stack A");
    print(B, "merge stack B");
    stack<int> merged;
    while (!A.empty() && !B.empty())
    {
        int first = A.top();
        int second = B.top();
        cout << first << " " << second << endl;
        if (first < second)
        {
            merged.push(first);
            A.pop();
            cout << "adding froom first " << first << endl;
        }
        else
        {
            merged.push(second);
            B.pop();
            cout << "adding froom second " << second << endl;
        }
    }
    print(merged, "bofore");
    while (!A.empty())
    {
        merged.push(A.top());
        A.pop();
    }
    while (!B.empty())
    {
        merged.push(B.top());
        B.pop();
    }

    while (!merged.empty())
    {

        A.push(merged.top());

        merged.pop();
    }

    print(A, "merged");
    return A;
}
