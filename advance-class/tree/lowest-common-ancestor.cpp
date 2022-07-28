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
 * @brief Find the lowest common ancestor in an unordered binary tree A, given two values, B and C, in the tree.
 * Lowest common ancestor: the lowest common ancestor (LCA) of two nodes and w in a tree or directed acyclic graph (DAG) is the lowest (i.e., deepest) node that has both v and w as descendants.
 *
 * @param A
 * @param B
 * @param C
 * @return int
 */
int lca(TreeNode *A, int B, int C);
TreeNode *find_lca(TreeNode *A, int B, int C);

int main(int argc, char **argv)
{
    system("clear");
    return 0;
}
bool isValuePresent(TreeNode *A, int value)
{
    if (A == NULL)
        return false;
    if (A->val == value)
        return true;

    return (isValuePresent(A->left, value) || isValuePresent(A->right, value));
}
TreeNode *find_lca(TreeNode *A, int B, int C)
{
    if (A == NULL)
        return NULL;
    if (!isValuePresent(A, B) || !isValuePresent(A, C))
        return NULL;
    if (A->val == B || A->val == C)
        return A;
    TreeNode *left = find_lca(A->left, B, C);
    TreeNode *right = find_lca(A->right, B, C);

    if (left != NULL && right != NULL)
        return A;
    if (left != NULL && right == NULL)
        return left;
    if (left == NULL && right != NULL)
        return right;
    return NULL;
}
int lca(TreeNode *A, int B, int C)
{
    if (!isValuePresent(A, B) || !isValuePresent(A, C))
        return -1;
    TreeNode *node = find_lca(A, B, C);
    return node == NULL ? 0 : node->val;
}