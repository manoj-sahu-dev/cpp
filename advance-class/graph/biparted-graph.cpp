#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief Given a undirected graph having A nodes. A matrix B of size M x 2 is given which represents the edges such that there is an edge between B[i][0] and B[i][1].
 * Find whether the given graph is bipartite or not.
 * A graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in
 *
 * Note:
 * There are no self-loops in the graph.
 * No multiple edges between two pair of vertices.
 * The graph may or may not be connected.
 * Nodes are Numbered from 0 to A-1.
 * Your solution will run on multiple testcases. If you are using global variables make sure to clear them.
 *
 */
class Solution
{
private:
    void print(vector<vector<int>> &A)
    {
        int asize = A.size();

        for (auto x : A)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool checkBipartite(vector<vector<int>> &adjacency_list, vector<int> &visited, int current_node, int flag)
    {
        visited[current_node] = flag;
        for (int i = 0; i < adjacency_list[current_node].size(); i++)
        {
            int current_edge = adjacency_list[current_node][i];
            if (visited[current_edge] == flag)
            {
                return false;
            }
            else if (visited[current_edge] == -1 && !checkBipartite(adjacency_list, visited, current_edge, 1 - flag))
            {
                return false;
            }
        }
        return true;
    }

public:
    int solve(int A, vector<vector<int>> &B)
    {
        vector<vector<int>> adjacency_list(A);
        int bsize = B.size();

        for (int i = 0; i < bsize; i++)
        {
            adjacency_list[B[i][0]].push_back(B[i][1]);
            adjacency_list[B[i][1]].push_back(B[i][0]);
        }
        print(adjacency_list);

        vector<int> visited(A, -1);

        for (int i = 0; i < A; i++)
        {
            if (visited[i] == -1 && !checkBipartite(adjacency_list, visited, i, 0))
            {
                return 0;
            }
        }
        return 1;
    }
};
int main(int argc, char const *argv[])
{
    system("clear");
    int A = 3;
    vector<vector<int>> B{{0, 1}, {0, 2}, {1, 2}};

    Solution solution;
    int result = solution.solve(A, B);
    cout << "it is biparted : " << result << endl;
    return 0;
}
