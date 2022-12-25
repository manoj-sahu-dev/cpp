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
void preorder_traversal(TreeNode *A);
void post_order_traversal(TreeNode *A);
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
    vector<int> A{1, 2, 3, 4, 5, 7, 8, 9, 10, 6, 13, 17, 19, 12, 15, 18, 20, 22, 23, 11, 14, 27, 28, 50, 52, 44, 54, 16, 21, 39, 47, 31, 53, 33, 55, 34, 64, 66, 69, 25, 26, 29, 30, 32, 85, 40, 86, 103, 156, 58, 131, 57, 92, 90, 167, 24, 48, 60, 61, 105, 109, 62, 134, 46, 49, 138, 166, 36, 43, 168, 170, 35, 65, 124, 129, 143, 146, 82, 88, 71, 72, 74, 75, 89, 91, 38, 45, 42, 68, 163, 229, 115, 118, 95, 231, 132, 230, -1, 378, 79, 141, 161, 295, 63, 148, 107, 171, 147, 155, -1, -1, 41, 70, 51, 142, 108, 176, 106, 178, 254, 255, 220, 263, 181, 182, 334, 335, 98, 133, 152, 154, 224, 343, -1, -1, 37, 84, 126, 135, 284, 381, 184, -1, 77, 81, 67, 87, 309, 311, 322, 324, 328, 354, 305, 360, 196, 222, 144, 218, 78, 94, 111, 187, 188, 193, 169, 197, 114, 179, 120, 190, 59, 102, 56, 113, 110, 125, 139, 186, -1, 164, 268, -1, 280, 282, 297, 298, 234, 241, 358, -1, 329, 331, -1, 261, -1, -1, 140, 219, 180, 287, -1, -1, -1, -1, 93, 183, 283, 361, 121, 185, -1, 290, 153, 300, 375, 376, 119, 123, 96, 177, 73, 76, 349, 353, 112, 262, -1, -1, 258, 259, -1, -1, 288, 352, 303, 371, -1, -1, -1, 276, -1, -1, -1, -1, -1, -1, -1, -1, 104, 117, 236, 332, 319, 368, 195, 279, -1, -1, -1, -1, 100, 101, 226, 228, 252, 312, 211, 337, -1, -1, -1, 382, -1, -1, 212, 214, 128, 162, 160, 165, 97, 173, -1, -1, -1, 314, -1, 351, -1, -1, 359, -1, -1, -1, -1, -1, -1, -1, -1, -1, 281, -1, 275, 355, -1, -1, 215, 216, 127, 232, 269, 270, -1, 192, -1, -1, -1, -1, -1, -1, 204, -1, 145, 278, 286, -1, 291, 299, -1, -1, 83, 172, 122, 233, 130, 136, 150, 274, 201, 264, 206, 227, 316, 346, 306, 350, 221, 235, -1, -1, -1, 379, 373, -1, -1, -1, -1, -1, 265, 341, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 347, 348, -1, -1, 202, -1, -1, -1, 158, 208, -1, -1, -1, -1, -1, -1, 157, 213, -1, -1, -1, 292, 370, 374, -1, -1, 380, -1, -1, -1, 159, 191, 151, 307, 99, 194, 237, 301, 80, 175, 199, 207, -1, -1, -1, -1, 271, 272, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 364, -1, -1, -1, -1, 240, 253, 198, 277, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 289, 308, 137, 246, 249, 250, -1, -1, -1, -1, -1, -1, -1, 336, 304, -1, -1, -1, -1, -1, -1, -1, -1, -1, 318, 320, -1, 200, 238, 344, 248, 317, 242, 243, -1, -1, 330, 363, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 267, -1, -1, 209, 315, -1, -1, -1, -1, -1, -1, -1, -1, 285, -1, 342, 357, -1, -1, -1, -1, -1, -1, -1, -1, 223, 225, 217, 333, 174, 302, -1, -1, 326, 327, 247, 338, 203, 321, -1, -1, 205, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 362, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 372, -1, -1, -1, 210, -1, -1, -1, 239, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 313, -1, 245, 366, -1, 367, 149, 244, 325, -1, -1, -1, -1, -1, 116, 189, -1, -1, -1, 266, 256, -1, -1, -1, -1, -1, -1, -1, 356, -1, 296, -1, -1, -1, -1, -1, -1, -1, -1, -1, 339, 340, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 310, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 323, 345, -1, -1, -1, -1, -1, -1, -1, -1, 369, -1, -1, -1, -1, -1, -1, -1, 251, 260, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 273, 365, -1, -1, -1, -1, 293, 294, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 377, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 257, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    print(A);
    TreeNode *tree = deserialize(A);
    preorder_traversal(tree);
    cout << endl;
    post_order_traversal(tree);
    cout << endl;
    // vector<vector<int>> ans = verticalOrderTraversal(tree);
    // print(ans);
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
    TreeNode *leftNode = NULL, *rightNode = NULL;
    TreeNode *root = new TreeNode(A[0]);
    q.push(root);
    TreeNode *cur = root;
    for (int i = 1; i < A.size() - 1; i += 2)
    {
        leftNode = new TreeNode(A[i]);
        rightNode = new TreeNode(A[i + 1]);
        cur = q.front();
        q.pop();
        if (A[i] != -1)
        {
            q.push(leftNode);
            cur->left = leftNode;
        }
        else
        {
            cur->left = NULL;
        }
        if (A[i + 1] != -1)
        {
            q.push(rightNode);
            cur->right = rightNode;
        }
        else
        {
            cur->right = NULL;
        }
    }
    return root;
}
void print(vector<int> &A)
{
    cout << "size: " << A.size() << ", elements: ";
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

void preorder_traversal(TreeNode *A)
{
    if (A == nullptr)
        return;

    cout << A->val << " ";
    preorder_traversal(A->left);
    preorder_traversal(A->right);
}

void post_order_traversal(TreeNode *A)
{
    if (A == nullptr)
        return;

    post_order_traversal(A->left);
    post_order_traversal(A->right);
    cout << A->val << " ";
}