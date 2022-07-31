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
 * @brief You are given a Binary Tree A with N nodes.
 * Write a function that returns the size of the largest subtree, which is also a Binary Search Tree (BST).
 * If the complete Binary Tree is BST, then return the size of the whole tree.
 * NOTE:
 * The largest subtree is the subtree with the most number of nodes.
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
}
