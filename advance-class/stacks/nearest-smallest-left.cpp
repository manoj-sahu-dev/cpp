#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief Given an array A, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
 * More formally,
 * G[i] for an element A[i] = an element A[j] such that
 * j is maximum possible AND
 * j < i AND
 * A[j] < A[i]
 * Elements for which no smaller element exist, consider the next smaller element as -1.
 *
 * @param A
 * @return vector<int>
 */
vector<int> find_nearest_smallest_left(vector<int> &A);
void print(vector<int> &A);
int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{4, 6, 10, 11, 7, 8, 3, 5};
    print(A);
    vector<int> ans = find_nearest_smallest_left(A);
    print(ans);
    return 0;
}

vector<int> find_nearest_smallest_left(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= A[i])
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