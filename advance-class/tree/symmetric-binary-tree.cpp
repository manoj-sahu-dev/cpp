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
 * @return TreeNode*
 */
TreeNode *isSymmetric(TreeNode *A);
int main(int argc, char **argv)
{
    system("clear");
    return 0;
}
TreeNode *isSymmetric(TreeNode *A)
{
}