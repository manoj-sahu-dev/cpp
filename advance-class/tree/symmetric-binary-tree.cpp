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
 * @brief Given a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 *
 * @param A
 * @return int
 */
int isSymmetric(TreeNode *A);
bool same(TreeNode *A, TreeNode *B);
int main(int argc, char **argv)
{
    system("clear");
    return 0;
}
bool same(TreeNode *A, TreeNode *B)
{
    if (A == NULL && B == NULL)
        return false;
    if (A != NULL && B != NULL)
        return A->val == B->val;
    return false;
}
int isSymmetric(TreeNode *A)
{
    if (A == NULL)
        return false;
    return same(A->left, A->right);
}