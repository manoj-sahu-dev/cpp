#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{

public:
    void print(vector<vector<int>> &vec)
    {
        cout << "content of vector: " << vec.size() << endl;
        int c = 0;
        for (auto x : vec)
        {
            cout << c++ << " -> ";
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int node, int parent)
    {
        visited[node] = true;
        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                bool cycle_detected = dfs(adj, visited, neighbor, node);
                if (cycle_detected)
                {
                    return true;
                }
            }
            else if (visited[neighbor] && neighbor != parent)
            {
                return true;
            }
        }

        return false;
    }

    int solve(int A, vector<vector<int>> &B)
    {
        print(B);
        vector<vector<int>> adj(A + 1);

        for (int i = 0; i < B.size(); i++)
        {
            int u = B[i][0];
            int v = B[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            cout << "i: " << i << ", u: " << u << " v: " << v << endl;
        }
        print(adj);

        vector<bool> visited(A + 1, false);

        for (int i = 0; i < A; i++)
        {
            if (!visited[i])
            {
                bool cyclic = dfs(adj, visited, i, -1);
                if (cyclic)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

int main(int argc, char **arg)
{
    system("clear");
    int A = 5;
    vector<vector<int>> B{{1, 2}};
    // vector<vector<int>> B{
    //     {1, 2},
    //     {1, 3},
    //     {2, 3},
    //     {1, 4},
    //     {4, 5}};

    Solution solution;
    int result = solution.solve(A, B);
    cout << "given graph has " << (result == 1 ? "cycle" : "No cycle") << endl;
    return 0;
}