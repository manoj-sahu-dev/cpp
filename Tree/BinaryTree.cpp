#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int isSameTree(TreeNode *A, TreeNode *B)
{
    if (A == NULL && B == NULL)
        return true;

    if (A != NULL && B != NULL)
    {
        return A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
    return false;
}

vector<int> getNodespreOrder(TreeNode *A)
{
    vector<int> data;
    stack<TreeNode> nodes;
    nodes.push(*A);
    while (nodes.size() > 0)
    {
        TreeNode node = nodes.top();
        nodes.pop();
        data.push_back(node.val);
        if (node.right != NULL)
            nodes.push(*node.right);
        if (node.left != NULL)
            nodes.push(*node.left);
    }
    return data;
}

vector<int> getNodesInOrder(TreeNode *A)
{
    vector<int> data;
    stack<TreeNode *> nodes;
    while (A != NULL || nodes.empty())
    {
        if (A != NULL)
        {
            nodes.push(A->left);
            A = A->left;
        }
        else
        {
            A = nodes.top();
            nodes.pop();
            data.push_back(A->val);
            A = A->right;
        }
    }
    return data;
}

vector<int> getNodesPostOrder(TreeNode *A)
{
    if (A == NULL)
        return {};
    vector<int> result;

    stack<TreeNode *> SNode1, SNode2;

    SNode1.push(A);
    while (!SNode1.empty())
    {
        TreeNode *temp = SNode1.top();
        SNode1.pop();
        SNode2.push(temp);

        if (temp->left != NULL)
            SNode1.push(temp->left);

        if (temp->right != NULL)
            SNode1.push(temp->right);
    }
    while (!SNode2.empty())
    {
        result.push_back(SNode2.top()->val);
        SNode2.pop();
    }
    return result;
}
int main()
{
    return 0;
}