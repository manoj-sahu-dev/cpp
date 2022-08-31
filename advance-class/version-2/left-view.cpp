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
 * @brief Given a binary tree of integers. Return an array of integers representing the left view of the Binary tree.
 * Left view of a Binary Tree is a set of nodes visible when the tree is visited from Left side
 * NOTE: The value comes first in the array which have lower level.
 *
 * @param A
 * @return vector<int>
 */
vector<int> solve(TreeNode *A);

TreeNode *deserialize(vector<int> &A);

int main(int argc, char **argv)
{
    system("clear"); // clean terminal, not tested in windows
    vector<int> A{7, 1, 15, 2, -1, -1, -1, -1};
    TreeNode *head = deserialize(A);

    return 0;
}

vector<int> solve(TreeNode *A)
{
    vector<int> result;

    return result;
}

TreeNode *deserialize(vector<int> &A)
{
    TreeNode *head = nullptr;
    if (A.size() == 0)
        return head;
    queue<TreeNode *> q;
    head = new TreeNode(A[0]);
    q.push(head);

    int size = A.size();
    for (int i = 1; i < size; i++)
    {
        int val = A[i];
        if (val != -1)
        {
            TreeNode *node = new TreeNode(val);
        }
    }
    return head;
}