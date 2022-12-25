#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &list)
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

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int next_node = graph[node][i];
        dfs(graph, visited, next_node);
    }
}

/**
 * @brief First Depth First Search
 *
 * You are given N towns (1 to N). All towns are connected via unique directed path as mentioned in the input.
 * Given 2 towns find whether you can reach the first town from the second without repeating any edge.
 * B C : query to find whether B is reachable from C.
 * Input contains an integer array A of size N and 2 integers B and C ( 1 <= B, C <= N ).
 * There exist a directed edge from A[i] to i+1 for every 1 <= i < N. Also, it's guaranteed that A[i] <= i for every 1 <= i < N.
 * NOTE: Array A is 0-indexed. A[0] = 1 which you can ignore as it doesn't represent any edge.
 * @param A
 * @param d
 * @param C
 * @return int
 */
int solve(vector<int> &A, const int B, const int C)
{
    int n = A.size();
    int c = C;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    print(adj);
    for (int i = 0; i < n; i++)
    {
        adj[A[i]].push_back(i + 1);
    }
    print(adj);
    dfs(adj, visited, c);
    return visited[B];
}

int main(int argc, char *argv[])
{
    system("clear");
    vector<int> A{1, 1, 2};
    int B = 2;
    int C = 1;
    int res = solve(A, B, C);
    cout << res << endl;
    return 0;
}