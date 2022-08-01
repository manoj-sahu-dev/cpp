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
TreeNode *construct(vector<int> &A, int start, int end);
TreeNode *sortedArrayToBST(const vector<int> &A);
vector<int> in_order_traversal(TreeNode *A);

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{1, 2};
    TreeNode *node = sortedArrayToBST(A);
    vector<int> in_order = in_order_traversal(node);
    print(in_order);
    return 0;
}

vector<int> in_order_traversal(TreeNode *A)
{
    vector<int> ans;
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
            ans.push_back(A->val);
            A = A->right;
        }
    }
    return ans;
}

TreeNode *construct(const vector<int> &A, int start, int end)
{
    if (start > end)
        return NULL;
    int middle = (start + end) / 2;
    cout << "start: " << start << ", end: " << end << ", middle: " << middle << endl;
    TreeNode *node = new TreeNode(A[middle]);
    node->left = construct(A, start, middle - 1);
    node->right = construct(A, middle + 1, end);
    return node;
}

TreeNode *sortedArrayToBST(const vector<int> &A)
{
    int start = 0, end = A.size() - 1;
    TreeNode *root = construct(A, start, end);
    return root;
}