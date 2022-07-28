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
 * @brief Given a binary tree of integers. Find the difference between the sum of nodes at odd level and sum of nodes at even level.
 *
 * NOTE: Consider the level of root node as 1.
 *
 * @param A
 * @return int
 */
int solve(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear");

    return 0;
}

int solve(TreeNode *A)
{
    if (A == NULL)
        return 0;

    int diff = 0, oddSum = 0, evenSum = 0;

    queue<TreeNode *> q;
    q.push(A);
    bool isEven = false;
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            isEven ? evenSum += node->val : oddSum += node->val;
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        isEven = !isEven;
    }
    diff = oddSum - evenSum;
    return diff;
}
