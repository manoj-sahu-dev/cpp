#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        // cout << "A[" << i << "] = " << A[i] << " ";
        cout << A[i] << " ";
    }
    cout << endl;
}
void printHash(unordered_map<int, int> &map)
{
    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << "key = " << (it->first) << ", value = " << it->second;
    }
    cout << endl;
}
void printHash(unordered_map<int, vector<int>> &map)
{
    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << "key = " << (it->first) << " : ";
        print(it->second);
    }
    cout << endl;
}

/**
 * @brief deserialize a Treenode from vector<int>
 *
 * @param A
 * @return TreeNode*
 */
TreeNode *deserialize(vector<int> A)
{
    TreeNode *head = new TreeNode(A[0]);
    queue<TreeNode *> q;
    q.push(head);
    int index = 0;
    cout << "head value = " << head->val << endl;
    while (!q.empty() && index < A.size() - 2)
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == nullptr)
            continue;
        int leftValue = A[++index];
        int rightValue = A[++index];

        cout << "leftValue = " << leftValue << ", rightValue = " << rightValue << ", index = " << index << endl;
        if (leftValue == -1)
            node->left = nullptr;
        else
            node->left = new TreeNode(leftValue);

        if (rightValue == -1)
            node->right = nullptr;
        else
            node->right = new TreeNode(rightValue);
        q.push(node->left);
        q.push(node->right);
    }
    return head;
}

/**
 * @brief Given a binary tree of integers denoted by root A.
 * Return an array of integers representing the top view of the Binary tree.
 * The top view of a Binary Tree is a set of nodes visible when the tree is visited from the top.
 * Return the nodes in any order.
 *
 * @param A
 * @return vector<int>
 */
vector<int> solve(TreeNode *A)
{
    if (A == nullptr)
        return vector<int>();
    vector<int> answer;
    queue<pair<int, TreeNode *>> q;
    pair first = make_pair(0, A);
    q.push(first);
    unordered_map<int, int> m;
    int minIndex = 0, maxIndex = 0;
    while (!q.empty())
    {
        pair<int, TreeNode *> p = q.front();
        q.pop();
        int index = p.first;
        TreeNode *node = p.second;
        cout << "index: " << index << " node: " << node->val << endl;
        if (!m[index])
            m[index] = node->val;
        if (node->left != nullptr)
        {
            pair<int, TreeNode *> left = make_pair(index - 1, node->left);
            q.push(left);
            minIndex = min(minIndex, index - 1);
        }
        if (node->right != nullptr)
        {
            pair<int, TreeNode *> right = make_pair(index + 1, node->right);
            q.push(right);
            maxIndex = max(maxIndex, index + 1);
        }
    }
    cout << "min: " << minIndex << " max: " << maxIndex << endl;
    printHash(m);
    for (auto kvp : m)
    {
        answer.push_back(kvp.second);
    }
    return answer;
}

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{7, 1, 15, 2, -1, -1, -1, -1};
    print(A);
    TreeNode *head = deserialize(A);
    vector<int> result = solve(head);
    print(result);
    return 0;
}