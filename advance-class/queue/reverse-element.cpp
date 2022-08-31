#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void print(vector<int> &A)
{
    cout << "content of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

/**
 * @brief Given an array of integers A and an integer B, we need to reverse the order of the first B elements of the array,
 * leaving the other elements in the same relative order.
 * NOTE: You are required to the first insert elements into an auxiliary queue then perform Reversal of first B elements.
 *
 * @param A
 * @param B
 * @return vector<int>
 */
vector<int> solve(vector<int> &A, int B)
{
    stack<int> st;
    queue<int> q;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (i < B)
        {
            st.push(A[i]);
        }
        else
        {
            q.push(A[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i < B)
        {
            A[i] = st.top();
            st.pop();
        }
        else
        {
            A[i] = q.front();
            q.pop();
        }
    }
    return A;
}

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{5, 17, 100, 11};
    int B = 2;
    print(A);
    vector<int> ans = solve(A, B);
    print(ans);
    return 0;
}
