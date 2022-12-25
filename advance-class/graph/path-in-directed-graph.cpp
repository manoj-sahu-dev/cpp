#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

bool has_path(int src, int dest, vector<vector<int>> &graph)
{
    queue<int> q;
    vector<int> visited(dest, false);
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        src = q.front();
        q.pop();
        for (auto x : graph[src])
        {
            if (x == dest)
                return true;
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return false;
}

/**
 * @brief Path in Directed Graph
 * Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2
 * such that there is a edge directed from node
 *
 * B[i][0] to node B[i][1].
 * Find whether a path exists from node 1 to node A.
 * Return 1 if path exists else return 0.
 * NOTE:
 * There are no self-loops in the graph.
 * There are no multiple edges between two nodes.
 * The graph may or may not be connected.
 * Nodes are numbered from 1 to A.
 * Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
 *
 * @param A
 * @param B
 * @return int
 */
int solve(int A, vector<vector<int>> &B)
{

    vector<vector<int>> graph(A + 1, vector<int>(0, 0));

    for (int i = 0; i < B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
    }
    print(graph);
    return has_path(1, A, graph);
}

int main(int argc, char **c)
{
    system("clear");
    // vector<vector<int>> B{
    //     {1, 2},
    //     {1, 4},
    //     {2, 5},
    //     {2, 3},
    //     {2, 4},
    //     {5, 3},
    //     {4, 3}};
    // vector<vector<int>> vect{
    //     {1, 2},
    //     {4, 1},
    //     {2, 4},
    //     {3, 4},
    //     {5, 2},
    //     {1, 3}};
    vector<vector<int>> B{
        {1, 2},
        {2, 3},
        {4, 3}};
    int res = solve(4, B);
    cout << res << endl;
    return 0;
}