#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Given preorder and inorder traversal of a tree, construct the binary tree.
 * NOTE: You may assume that duplicates do not exist in the tree.
 *
 * @param A
 * @param B
 * @return TreeNode*
 */
TreeNode *buildTree(vector<int> &A, vector<int> &B);

int main(int argc, char **argv)
{
    system("clear");

    return 0;
}

TreeNode *buildTree(vector<int> &A, vector<int> &B)
{
}
