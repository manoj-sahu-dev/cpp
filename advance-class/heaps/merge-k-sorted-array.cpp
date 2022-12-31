#include <bits/stdc++.h>

using namespace std;

struct Node
{
public:
    int x, y, data;
    Node(int x, int y, int data) : x(x), y(y)
    {
        this->data = data;
    }
};
class compareNode
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
void print(vector<int> &v)
{
    for (auto x : v)
        cout << x << "  ";
    cout << endl;
}
void print(vector<vector<int>> &v)
{
    for (auto x : v)
    {
        print(x);
    }
    cout << endl;
}
void print(priority_queue<Node *, vector<Node *>, compareNode> gq)
{
    while (!gq.empty())
    {
        cout << gq.top()->data << "  ";
        gq.pop();
    }

    cout << endl;
}

/**
 * @brief You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order).
 * You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
 *
 * @param kArrays
 * @param k
 * @return vector<int>
 */
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    cout << "number of arrays: " << k << endl;

    priority_queue<Node *, vector<Node *>, compareNode> minHeap;
    int column = 0;
    for (int i = 0; i < k; i++)
    {
        Node *node = new Node(i, column, kArrays[i][column]);

        minHeap.push(node);
    }
    column++;
    print(minHeap);
    vector<int> result;
    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        result.push_back(top->data);
        minHeap.pop();

        int row = top->x;
        int col = top->y;
        int nextCol = col + 1;
        if (nextCol < kArrays[row].size())
        {
            Node *node = new Node(row, nextCol, kArrays[row][nextCol]);
            minHeap.push(node);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    system("clear");
    vector<vector<int>> kArrays{
        {1, 5, 9},
        {45, 90},
        {2, 6, 78, 100, 234},
        {0}};
    print(kArrays);
    vector<int> result = mergeKSortedArrays(kArrays, kArrays.size());
    print(result);
    return 0;
}
