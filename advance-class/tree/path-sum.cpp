#include <iostream>
#include <stack>
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
 * @brief Given a binary tree and a sum,
 * determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 * @param A
 * @param B
 * @return int
 */
int hasPathSum(TreeNode *A, int B);

int main()
{
    system("clear");
    return 0;
}

int hasPathSum(TreeNode *A, int B)
{
    if (A == nullptr)
        return 0;
    B -= A->val;

    if (A->left == nullptr && A->right == nullptr)
        return 1;

    return hasPathSum(A->left, B) || hasPathSum(A->right, B);
}