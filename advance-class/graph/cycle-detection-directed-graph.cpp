#include <iostream>
#include <vector>

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

    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &dfs_visited, int node)
    {
        visited[node] = true;
        dfs_visited[node] = true;

        for (auto neighbors : adj[node])
        {
            if (!visited[neighbors])
            {
                bool cycle_detected = dfs(adj, visited, dfs_visited, neighbors);
                if (cycle_detected)
                {
                    return true;
                }
            }
            else if (dfs_visited[neighbors] && visited[neighbors])
            {
                return true;
            }
        }
        dfs_visited[node] = false;
        return false;
    }
    /**
     * @brief Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].
     * Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.
     * NOTE:
     * The cycle must contain atleast two nodes.
     * There are no self-loops in the graph.
     * There are no multiple edges between two nodes.
     * The graph may or may not be connected.
     * Nodes are numbered from 1 to A.
     * Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
     *
     */
    int solve(int A, vector<vector<int>> &B)
    {
        print(B);
        vector<vector<int>> adj(A + 1);

        for (int i = 0; i < B.size(); i++)
        {
            int u = B[i][0];
            int v = B[i][1];

            adj[u].push_back(v);
        }
        print(adj);

        vector<bool> visited(A + 1, false);
        vector<bool> dfs_visited(A + 1, false);

        for (int i = 1; i <= A; i++)
        {
            // cout << "i: " << i << endl;
            if (!visited[i])
            {
                bool cycle_detected = dfs(adj, visited, dfs_visited, i);
                if (cycle_detected)
                    return 1;
            }
        }

        return 0;
    }
};

int main(int argc, char **arg)
{
    system("clear");
    int A = 5;
    // vector<vector<int>> B{{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    vector<vector<int>> B{{1, 2}, {1, 3}, {2, 3}, {1, 4}, {4, 3}, {4, 5}, {3, 5}};
    // vector<vector<int>> B{{1, 2}, {2, 3}, {3, 4}, {4, 5}};

    Solution solution;
    int result = solution.solve(A, B);
    cout << "given graph has " << (result == 1 ? "cycle" : "no cycle") << endl;
    return 0;
}