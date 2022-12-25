#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    void create_adjacency_list(vector<pair<int, int>> &edges, vector<vector<int>> &adj)
    {
        int n = edges.size();
        for (int i = 1; i < n; i++)
        {
            int first = edges[i].first;
            int second = edges[i].second;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
    }
    void bfs(vector<vector<int>> adj, vector<bool> &visited, vector<int> &result, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            int front_node = q.front();
            q.pop();
            result.push_back(front_node); // store front node in result
            cout << "pushing edge: " << front_node << endl;

            for (int i : adj[front_node])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

public:
    void print(vector<int> &data)
    {
        for (auto x : data)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    void print(vector<vector<int>> list)
    {
        cout << "list is : " << list.size() << " * " << list[0].size() << endl;
        int index = 0;
        for (vector<int> lst : list)
        {
            cout << index << " -> ";
            for (int l : lst)
            {
                cout << l << " ";
            }
            index += 1;
            cout << endl;
        }
        cout << endl;
    }
    vector<int> BFS(int vertex, vector<pair<int, int>> edges)
    {
        // Write your code here
        int n = edges.size() - 1;
        vector<vector<int>> adj(n + 1, vector<int>(0));
        vector<bool> visited(n + 1, false);
        print(adj);
        create_adjacency_list(edges, adj);
        print(adj);
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cout << i << " -> " << endl;
                bfs(adj, visited, result, i);
            }
        }
        return result;
    }
};

int main(int argc, char **c)
{
    system("clear");
    vector<pair<int, int>> edges{
        {4, 4},
        {0, 1},
        {0, 3},
        {1, 2},
        {2, 3}};
    Graph g;
    vector<int> ans = g.BFS(0, edges);
    g.print(ans);
    return 0;
}