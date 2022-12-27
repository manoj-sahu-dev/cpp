#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    bool is_cycle_bfs(vector<vector<int>> adj, vector<bool> &visited, int current)
    {
        vector<int> parent(visited.size(), 0);
        parent[current] = -1;
        visited[current] = true;
        queue<int> q;
        q.push(current);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int i = 0; i < adj[front].size(); i++)
            {
                int neighbor = adj[front][i];

                if (visited[neighbor] && neighbor != parent[front])
                {
                    return true;
                }
                else if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = front;
                }
            }
        }

        if (visited[current])
        {
            return true;
        }
        return false;
    }

public:
    string cycleDetection(vector<vector<int>> &edges, int n, int m)
    {

        vector<bool> visited(n + 1, false);
        vector<vector<int>> adj;
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bool ans = is_cycle_bfs(adj, visited, i);
                if (ans)
                    return "Yes";
            }
        }

        return "No";
    }
};

int main(int argc, char **arg)
{
    system("clear");
    return 0;
}