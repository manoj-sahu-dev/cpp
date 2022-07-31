#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief You are given a binary tree represented by root A.
 * Assume a BST is defined as follows:
 * 1) The left subtree of a node contains only nodes with keys less than the node's key.
 * 2) The right subtree of a node contains only nodes with keys greater than the node's key.
 * 3) Both the left and right subtrees must also be binary search trees.
 *
 * @param A
 * @return int
 */
int isValidBST(TreeNode *A);

bool isBST(TreeNode *A, int minVal, int maxVal);
int main(int argc, char **argv)
{
    system("clear");

    return 0;
}

bool isBST(TreeNode *A, int minVal, int maxVal)
{
    if (A == NULL)
        return true;

    if (A->val < minVal || A->val > maxVal)
        return false;
    return (isBST(A->left, minVal, A->val - 1) && isBST(A->right, A->val + 1, maxVal));
}

int isValidBST(TreeNode *A)
{
    return isBST(A, INT_MIN, INT_MAX);
}
