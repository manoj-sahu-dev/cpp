#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Given preorder and inorder traversal of a tree, construct the binary tree.
 * NOTE: You may assume that duplicates do not exist in the tree.
 *
 * @param A
 * @param B
 * @return TreeNode*
 */
TreeNode *buildTree(vector<int> &A, vector<int> &B);
void createMap(vector<int> &A, map<int, int> &m);
TreeNode *buildTree(vector<int> &preOrder, vector<int> &inOrder, int &preOrderIndex, int preOrderEnd, int inOrderStart, int inOrderEnd, map<int, int> &indexMap);

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

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{1, 2, 3};
    vector<int> B{2, 1, 3};
    TreeNode *node = buildTree(A, B);
    vector<int> ans = inorder_traversal(node);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = preorder_traversal(node);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
void createMap(vector<int> &A, map<int, int> &m)
{
    for (int i = 0; i < A.size(); i++)
        m[A[i]] = i;
}

TreeNode *buildTree(vector<int> &preOrder, vector<int> &inOrder, int &preOrderIndex, int preOrderEnd, int inOrderStart, int inOrderEnd, map<int, int> &indexMap)
{
    if (preOrderIndex > preOrderEnd || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int element = preOrder[preOrderIndex];
    TreeNode *node = new TreeNode(element);
    int position = indexMap[element];
    preOrderIndex += 1;

    node->left = buildTree(preOrder, inOrder, preOrderIndex, preOrderEnd, inOrderStart, position - 1, indexMap);
    node->right = buildTree(preOrder, inOrder, preOrderIndex, preOrderEnd, position + 1, inOrderEnd, indexMap);
    return node;
}

TreeNode *buildTree(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int preOrderIndex = 0;
    map<int, int> indexMap;
    for (int i = 0; i < B.size(); i++)
        indexMap[B[i]] = i;
    TreeNode *ans = buildTree(A, B, preOrderIndex, n, 0, n - 1, indexMap);
    return ans;
}