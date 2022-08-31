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
 * @brief Given two BST's A and B, return the (sum of all common nodes in both A and B) % (109 +7) .
 * In case there is no common node, return 0.
 * NOTE:
 * Try to do it one pass through the trees.
 *
 * @param A
 * @param B
 * @return int
 */
int solve(TreeNode *A, TreeNode *B);
void print_inorder(TreeNode *A)
{
    if (A == nullptr)
        return;
    print_inorder(A->left);
    cout << A->val << " ";
    print_inorder(A->right);
}
TreeNode *deserialize(vector<int> &A)
{
    TreeNode *head = new TreeNode(A[0]);
    queue<TreeNode *> queues;
    queues.push(head);
    int index = 0;
    while (!queues.empty())
    {
        TreeNode *node = queues.front();
        if (node == nullptr)
            continue;
        int leftValue = A[++index];
        int rightValue = A[++index];

        if (leftValue == -1)
            node->left = nullptr;
        else
            node->left = new TreeNode(leftValue);

        if (rightValue == -1)
            node->right = nullptr;
        else
            node->right = new TreeNode(rightValue);
        queues.push(node->left);
        queues.push(node->right);
    }
    return head;
}

int main(int argc, char **argv)
{
    system("clear");
    vector<int> des1{31, 25, 18, 30, 14, 21, 28, 33, 6, 17, 20, 22, 27, 29, 31, 43, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    vector<int> des2{51, 18, 11, 24, 6, 14, 21, 28, 4, 7, 12, 16, 19, 22, 25, 31, -1, 5, -1, 9, -1, 13, 15, 17, -1, 20, -1, 23, -1, 26, 30, 34, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *A = deserialize(des1);
    TreeNode *B = deserialize(des2);
    print_inorder(A);
    cout << endl;
    // print_inorder(B);
    return 0;
}

int solve(TreeNode *A, TreeNode *B)
{
    stack<TreeNode *> first, second;
    int ans = 0, modulo = 1000000007;
    while (true)
    {
        if (A != nullptr)
        {
            first.push(A);
            A = A->left;
        }
        else if (B != nullptr)
        {
            second.push(B);
            B = B->left;
        }
        else if (!first.empty() && !second.empty())
        {
            A = first.top();
            B = second.top();

            if (A->val == B->val)
            {
                first.pop();
                second.pop();
                ans += A->val % modulo;
                ans = ans % modulo;
                A = A->right;
                B = B->right;
            }
            else if (A->val < B->val)
            {
                first.pop();
                A = A->right;
                B = nullptr;
            }
            else if (A->val > B->val)
            {
                second.pop();
                B = B->right;
                A = nullptr;
            }
        }
        else
        {
            break;
        }
    }
    return ans;
}