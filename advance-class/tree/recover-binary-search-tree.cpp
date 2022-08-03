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
 * @brief Two elements of a binary search tree (BST), represented by root A are swapped by mistake.
 * Tell us the 2 values swapping which the tree will be restored.
 * A solution using O(n) space is pretty straightforward. Could you devise a constant space solution?
 *
 * @param A
 * @return vector<int>
 */
vector<int> recoverTree(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear");

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    vector<int> result = recoverTree(root);
    for (int x : result)
    {
        cout << x << endl;
    }
    return 0;
}

vector<int> recoverTree(TreeNode *A)
{
    TreeNode *prev = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;

    stack<TreeNode *> S;
    vector<int> sn;
    cout << " - start - " << endl;
    while (A || !S.empty())
    {
        while (A)
        {

            S.push(A);
            sn.push_back(A->val);
            A = A->left;
        }
        if (sn.size() > 0)
        {
            cout << "stack contents" << endl;
            for (int x : sn)
                cout << x << " ";
            cout << endl;
        }
        A = S.top();
        S.pop();
        sn.pop_back();
        cout << "popped: " << A->val << endl;
        if (prev && prev->val > A->val)
        {
            if (!first)
            {
                first = prev;
            }
            second = A;
        }

        prev = A;
        A = A->right;
        cout << "--------------------------------" << endl;
    }

    swap(first->val, second->val);
    return {first->val, second->val};
}