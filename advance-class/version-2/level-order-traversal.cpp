#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Given a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 *
 * @param A
 * @return vector<vector<int>>
 */
vector<vector<int>> levelOrder(TreeNode *A)
{
    vector<vector<int>> result;
    if (A == nullptr)
        return result;

    queue<TreeNode *> nodes;
    nodes.push(A);

    while (!nodes.empty())
    {
        vector<int> level;

        int size = nodes.size();

        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = nodes.front();
            nodes.pop();

            level.push_back(node->val);

            if (node->left != nullptr)
                nodes.push(node->left);

            if (node->right != nullptr)
                nodes.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int main(int argc, char **argv)
{
    return 0;
}
