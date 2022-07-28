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
 * @param A
 * @return vector<vector<int>>
 */
vector<vector<int>> zigzagLevelOrder(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear");
    return 0;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *A)
{
    vector<vector<int>> result;

    if (A == NULL)
        return result;
    queue<TreeNode *> q;
    q.push(A);

    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = node->val;

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        leftToRight = !leftToRight;
        result.push_back(ans);
    }

    return result;
}
