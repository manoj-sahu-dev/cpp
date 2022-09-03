#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Given a binary tree of integers denoted by root A. Return an array of integers representing the right view of the Binary tree.
 * Right view of a Binary Tree is a set of nodes visible when the tree is visited from Right side.
 *
 * @param A
 * @return vector<int>
 */
vector<int> solve(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear"); // clean terminal, not tested in windows
    vector<int> A{7, 1, 15, 2, -1, -1, -1, -1};

    return 0;
}

vector<int> solve(TreeNode *A)
{
    vector<int> result;
    if (A == nullptr)
        return result;

    queue<TreeNode *> q;
    q.push(A);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            if (i == (size - 1))
            {
                result.push_back(node->val);
            }
        }
    }
    return result;
}