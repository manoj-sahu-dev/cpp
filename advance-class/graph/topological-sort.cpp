#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
private:
    void print(vector<vector<int>> &v)
    {
        int i = 0;
        for (auto x : v)
        {
            cout << i++ << " -> ";
            print(x);
        }
        cout << endl;
    }

public:
    void print(vector<int> &v)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }
    vector<int> solve(int A, vector<vector<int>> &B)
    {
        print(B);
        vector<int> res;
        vector<vector<int>> graph(A + 1);
        vector<int> in_degree(A + 1);

        int N = B.size();

        for (int i = 0; i < N; i++)
        {
            int u = B[i][0];
            int v = B[i][1];

            graph[u].push_back(v);
            in_degree[v]++;
        }

        print(in_degree);
        print(graph);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i <= A; i++)
        {
            if (in_degree[i] == 0)
            {
                pq.push(i);
            }
        }

        while (!pq.empty())
        {
            int front = pq.top();
            pq.pop();
            cout << front << endl;
            res.push_back(front);

            for (auto neighbor : graph[front])
            {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0)
                {
                    pq.push(neighbor);
                }
            }
        }

        return res;
    }
    void show_pq(priority_queue<int, vector<int>, greater<int>> gq)
    {
        while (!gq.empty())
        {
            cout << '\t' << gq.top();
            gq.pop();
        }
        cout << '\n';
    }
    void test_min_heap(int size = 10)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < size; i++)
        {
            q.push(rand() % (size * 10));
        }
        show_pq(q);
        show_pq(q);
    }
};

int main(int argc, char **arg)
{
    system("clear");
    Solution solution;
    solution.test_min_heap();
    // int A = 6;
    // vector<vector<int>> B{{6, 3}, {6, 1}, {5, 1}, {5, 2}, {3, 4}, {4, 2}};
    // int A = 4;
    // vector<vector<int>> B{{1, 2}, {2, 3}, {2, 4}, {3, 4}, {4, 1}};
    int A = 8;
    vector<vector<int>> B{{1, 4}, {1, 2}, {4, 2}, {4, 3}, {3, 2}, {5, 2}, {3, 5}, {8, 2}, {8, 6}};
    vector<int> res = solution.solve(A, B);
    solution.print(res);
    return 0;
}