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
 * @brief Given a binary tree A, invert the binary tree and return it.
 * Inverting refers to making the left child the right child and vice versa.
 *     1
 *   /   \
 *  2     3
 * output -
 *      1
 *    /   \
 *   3     2
 * @param A
 * @return TreeNode*
 */
TreeNode *invertTree(TreeNode *A);
int main(int argc, char **argv)
{
    system("clear");
    return 0;
}

TreeNode *invertTree(TreeNode *A)
{
    if (A == NULL)
        return NULL;

    invertTree(A->left);
    invertTree(A->right);
    swap(A->left, A->right);
    return A;
}
