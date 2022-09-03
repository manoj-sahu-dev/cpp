#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void print(vector<int> &A);
void print(vector<vector<int>> &A);
void print(unordered_map<int, vector<int>> &map);
TreeNode *deserialize(vector<int> &A);
/**
 * @brief Given a binary tree, return a 2-D array with vertical order traversal of it.
 *  Go through the example and image for more details.
 * https://s3.ap-south-1.amazonaws.com/scaler-production-domestic/public_assets/assets/000/000/071/original/378.jpeg?1614507246
 *
 * @param A
 * @return vector<vector<int>>
 */
vector<vector<int>> verticalOrderTraversal(TreeNode *A);

int main(int argc, char **argv)
{
    system("clear"); // clean terminal, not tested in windows
    vector<int> A{6, 3, 7, 2, 5, -1, 9};
    print(A);
    TreeNode *tree = deserialize(A);
    vector<vector<int>> ans = verticalOrderTraversal(tree);
    print(ans);
    return 0;
}

vector<vector<int>> verticalOrderTraversal(TreeNode *A)
{
    vector<vector<int>> result;
    if (A == nullptr)
        return result;
    unordered_map<int, vector<int>> map;
    pair p = make_pair(0, A);
    queue<pair<int, TreeNode *>> q;
    q.push(p);
    int minIndex = 0, maxIndex = 0;

    while (!q.empty())
    {
        pair<int, TreeNode *> p = q.front();
        q.pop();

        int index = p.first;
        TreeNode *tree = p.second;
        map[index].push_back(tree->val);
        if (tree->left != nullptr)
        {
            q.push(make_pair(index - 1, tree->left));
            minIndex = min(minIndex, index - 1);
        }
        if (tree->right != nullptr)
        {
            q.push(make_pair(index + 1, tree->right));
            maxIndex = max(maxIndex, index + 1);
        }
    }
    cout << "minIndex: " << minIndex << ", maxIndex: " << maxIndex << endl;
    print(map);
    for (int i = minIndex; i <= maxIndex; i++)
    {
        result.push_back(map[i]);
    }
    return result;
}

TreeNode *deserialize(vector<int> &A)
{
    queue<TreeNode *> q;
    TreeNode *head = new TreeNode(A[0]);
    cout << "head -> " << head->val << endl;
    q.push(head);
    int index = 0, size = A.size();
    while (!q.empty() && index < size - 2)
    {
        TreeNode *node = q.front();
        q.pop();

        int leftValue = A[++index];
        int rightValue = A[++index];

        node->left = leftValue == -1 ? nullptr : new TreeNode(leftValue);
        node->right = rightValue == -1 ? nullptr : new TreeNode(rightValue);
        cout << "left value: " << leftValue << ", right value: " << rightValue << endl;
        q.push(node->left);
        q.push(node->right);
    }
    return head;
}
void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

void print(vector<vector<int>> &A)
{
    for (int i = 0; i < A.size(); i++)
        print(A[i]);
    cout << endl;
}

void print(unordered_map<int, vector<int>> &map)
{
    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << "key = " << (it->first) << " : ";
        print(it->second);
    }
    cout << endl;
}