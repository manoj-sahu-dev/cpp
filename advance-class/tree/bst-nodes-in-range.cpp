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
 * @brief Given a binary search tree of integers. You are given a range B and C.
 * Return the count of the number of nodes that lie in the given range.
 *
 * @param A
 * @param B
 * @param C
 * @return int
 */
int solve(TreeNode *A, int B, int C);

int main(int argc, char **argv)
{
    system("clear");
    return 0;
}

int solve(TreeNode *A, int B, int C)
{
    if (A == NULL)
        return 0;
    if (A->val >= B && A->val <= C)
    {
        return 1 + solve(A->left, B, C) + solve(A->right, B, C);
    }
    else if (A->val < B)
    {
        return solve(A->left, B, C);
    }
    else
    {
        return solve(A->right, B, C);
    }
}