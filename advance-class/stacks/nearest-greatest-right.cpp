#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief Given an array A, find the next greater element G[i] for every element A[i] in the array.
 * The next greater element for an element A[i] is the first greater element on the right side of A[i] in the array, A.
 *
 * More formally:
 * G[i] for an element A[i] = an element A[j] such that
 *     j is minimum possible AND
 *     j > i AND
 *     A[j] > A[i]
 *
 * Elements for which no greater element exists, consider the next greater element as -1.
 *
 * @param A
 * @return vector<int>
 */
vector<int> find_nearest_greatest_right(vector<int> &A);
void print(vector<int> &A);
int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{4, 5, 2, 10};
    print(A);
    vector<int> ans = find_nearest_greatest_right(A);
    print(ans);
    return 0;
}

vector<int> find_nearest_greatest_right(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= A[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            res[i] = -1;
        }
        else
        {
            res[i] = st.top();
        }

        st.push(A[i]);
    }
    return res;
}
void print(vector<int> &A)
{
    cout << "content if vecotr: ";
    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}