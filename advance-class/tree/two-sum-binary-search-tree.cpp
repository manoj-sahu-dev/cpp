#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Given a binary search tree A, where each node contains a positive integer, and an integer B,
 * you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.
 * Return 1 to denote that two such nodes exist. Return 0, otherwise.
 *
 * @param A
 * @param B
 * @return int
 */
int t2Sum(TreeNode *A, int B);
vector<int> in_order_traversal(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear");

    return 0;
}

vector<int> in_order_traversal(TreeNode *A)
{
    vector<int> result;
    stack<TreeNode *> st;
    while (A != NULL || !st.empty())
    {
        if (A != NULL)
        {
            st.push(A);
            A = A->left;
        }
        else
        {
            A = st.top();
            st.pop();
            result.push_back(A->val);
            A = A->right;
        }
    }
    return result;
}

int t2Sum(TreeNode *A, int B)
{
    vector<int> in_order = in_order_traversal(A);
    int i = 0, j = in_order.size() - 1;

    while (i < j)
    {
        int sum = in_order[i] + in_order[j];

        if (sum == B)
        {
            return 1;
        }
        else if (sum < B)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}
