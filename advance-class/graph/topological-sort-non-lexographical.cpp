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
        vector<int> in_degree(A + 1, 0);

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

        queue<int> q;

        for (int i = 1; i <= N; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            res.push_back(front);
            q.pop();
            for (auto neighbor : graph[front])
            {
                in_degree[neighbor]--;

                if (in_degree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        return res;
    }
};

int main(int argc, char **arg)
{
    system("clear");
    int A = 6;
    vector<vector<int>> B{{6, 3}, {6, 1}, {5, 1}, {5, 2}, {3, 4}, {4, 2}};
    Solution solution;
    vector<int> result = solution.solve(A, B);
    solution.print(result);
    return 0;
}