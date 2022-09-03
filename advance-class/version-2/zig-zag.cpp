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
 * @brief Given a binary tree, return the zigzag level order traversal of its nodes values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 *
 */
vector<vector<int>> zigzagLevelOrder(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear"); // clean terminal, not tested in windows
    vector<int> A{7, 1, 15, 2, -1, -1, -1, -1};

    return 0;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *A)
{
    vector<vector<int>> result;
    if (A == nullptr)
        return result;

    queue<TreeNode *> q;
    q.push(A);

    bool left = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size, 0);
        for (int i = 0; i < size; i++)
        {
            int index = left ? i : size - i - 1;

            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            ans[index] = node->val;
        }
        result.push_back(ans);
        left = !left;
    }
    return result;
}