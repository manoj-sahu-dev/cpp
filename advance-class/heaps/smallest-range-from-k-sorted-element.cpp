#include <bits/stdc++.h>

using namespace std;

struct Node
{
public:
    int row, col, data;
    Node(int row, int col, int data) : row(row), col(col)
    {
        this->data = data;
    }
};

class SmallestRange
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }

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
    void print(priority_queue<Node *, vector<Node *>, SmallestRange> gq)
    {
        while (!gq.empty())
        {
            cout << gq.top()->data << "  ";
            gq.pop();
        }

        cout << endl;
    }
    /**
     * @brief You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order.
     * You need to find the minimum length of a range such that at least one element of each list must be included in that range.
     * @link https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356
     * @param a
     * @param k
     * @param n
     * @return int
     */
    int kSorted(vector<vector<int>> &a, int k, int n)
    {
        print(a);

        priority_queue<Node *, vector<Node *>, SmallestRange> pq;
        int minimum = INT_MAX, maximum = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            Node *node = new Node(i, 0, a[i][0]);
            if (node->data < minimum)
                minimum = node->data;

            if (node->data > maximum)
                maximum = node->data;

            pq.push(node);
        }
        print(pq);

        int start = minimum, end = maximum;
        int range = maximum - minimum;
        while (!pq.empty())
        {
            Node *node = pq.top();
            pq.pop();
            minimum = node->data;
            if (maximum - minimum < end - start)
            {
                start = minimum;
                end = maximum;
            }

            if (node->col < n)
            {
                int next_col = node->col + 1;
                maximum = max(maximum, a[node->row][next_col]);
                Node *next_node = new Node(node->row, next_col, a[node->row][next_col]);
                pq.push(next_node);
            }
            else
            {
                break;
            }
        }

        return 1 + end - start;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    vector<vector<int>> a{
        {4, 7, 30},
        {1, 2, 12},
        {20, 40, 50}};
    int n = a.size();
    int k = a[0].size();

    SmallestRange smallestRange;

    int range = smallestRange.kSorted(a, k, n);
    cout << range << endl;
    return 0;
}
