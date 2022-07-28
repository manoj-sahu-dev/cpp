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
 * @brief Given a binary tree of integers. Return an array of integers representing the left view of the Binary tree.
 * Left view of a Binary Tree is a set of nodes visible when the tree is visited from Left side
 *
 * NOTE: The value comes first in the array which have lower level.
 *
 * @param A
 * @return vector<int> left view of the Binary Tree
 */
vector<int> solve(TreeNode *A);

int main(int argc, char *argv[])
{
    system("clear");
    return 0;
}

vector<int> solve(TreeNode *A)
{
    if (A == NULL)
        return {};

    queue<TreeNode *> q;
    vector<int> ans;
    q.push(A);
    while (!q.empty())
    {

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(node->val);
            }
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
    }
    return ans;
}
