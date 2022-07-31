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

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

vector<int> inorder_traversal(TreeNode *A);
vector<int> preorder_traversal(TreeNode *A);
/**
 * @brief Given a binary tree A, flatten it to a linked list in-place.
 * The left child of all nodes should be NULL.
 *
 * @param A
 * @return TreeNode*
 */
TreeNode *flatten(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear");
    TreeNode *A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->left->left = new TreeNode(3);
    A->left->right = new TreeNode(4);
    A->right = new TreeNode(5);
    A->right->right = new TreeNode(6);
    vector<int> preorder = preorder_traversal(A);
    print(preorder);
    A = flatten(A);
    print(preorder);
    return 0;
}
vector<int> preorder_traversal(TreeNode *A)
{
    vector<int> ans;
    stack<TreeNode *> st;
    if (A == NULL)
        return ans;
    st.push(A);
    while (!st.empty())
    {
        A = st.top();
        st.pop();
        ans.push_back(A->val);
        if (A->right)
        {
            st.push(A->right);
        }
        if (A->left)
        {
            st.push(A->left);
        }
    }
    return ans;
}

vector<int> inorder_traversal(TreeNode *A)
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

TreeNode *flatten(TreeNode *A)
{
    // if (A == NULL)
    //     return NULL;
    // vector<int> preorder = preorder_traversal(A);
    // print(preorder);

    // int i = 0, n = preorder.size();
    // TreeNode *head = new TreeNode(preorder[0]), *tail = head;
    // for (i = 1; i < n; i++)
    // {
    //     tail->right = new TreeNode(preorder[i]);
    //     tail = tail->right;
    // }
    // A = head;
    // return A;

    TreeNode *current = A;
    while (current != NULL)
    {
        if (current->left != NULL)
        {
            TreeNode *prev = current->left;
            while (prev->right != NULL)
            {
                prev = prev->right;
            }
            prev->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
    return A;
}