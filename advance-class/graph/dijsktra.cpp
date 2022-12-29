#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> int_pair;

class Dijkstra
{
public:
    void print(vector<int> &v)
    {
        for (auto x : v)
        {
            cout << x << "  ";
        }
        cout << endl;
    }
    void print(vector<vector<int>> &v)
    {
        int i = 0;
        for (auto x : v)
        {
            cout << '[' << i++ << "]  ->  ";
            print(x);
        }
        cout << endl;
    }
    void print(vector<vector<int_pair>> &adj)
    {
        int i = 0;
        for (auto x : adj)
        {
            cout << '[' << i++ << "] -> ";
            for (int m = 0; m < x.size(); m++)
            {
                auto y = x[m];
                cout << "(" << y.first << ", " << y.second << ")";
                if (m == x.size() - 1)
                {
                    cout << " ";
                }
                else
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }

    void print(priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq)
    {
        while (!pq.empty())
        {

            int_pair p = pq.top();
            cout << "(" << p.first << ", " << p.second << ")" << endl;
            pq.pop();
        }
        cout << '\n';
    }

    vector<int> solve(int A, vector<vector<int>> &B, int C)
    {
        print(B);

        vector<vector<int_pair>> adj(A);

        for (int i = 0; i < B.size(); i++)
        {
            int u = B[i][0];
            int v = B[i][1];
            int w = B[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        print(adj);
        vector<int> visited(A, false);
        vector<int> distance(A, INT_MAX);

        priority_queue<int_pair, vector<int_pair>, greater<int_pair>> pq;

        distance[C] = 0;
        pq.push(make_pair(0, C));

        while (!pq.empty())
        {
            int_pair p = pq.top();
            pq.pop();

            int node = p.second;

            if (visited[node])
                continue;
            visited[node] = true;

            for (auto neighbour : adj[node])
            {
                int current_node = neighbour.first;
                int current_distance = neighbour.second;

                if (distance[node] + current_distance < distance[current_node])
                {
                    distance[current_node] = distance[node] + current_distance;
                    pq.push(make_pair(distance[current_node], current_node));
                }
            }
        }
        for (int i = 0; i < distance.size(); i++)
        {
            if (distance[i] == INT_MAX)
                distance[i] = -1;
        }
        return distance;
    }
};

int main(int argc, char *argv[])
{
    system("clear");
    int A = 6;
    vector<vector<int>> B{
        {0, 4, 9},
        {3, 4, 6},
        {1, 2, 1},
        {2, 5, 1},
        {2, 4, 5},
        {0, 3, 7},
        {0, 1, 1},
        {4, 5, 7},
        {0, 5, 1}};
    int C = 4;

    // int A = 5;
    // vector<vector<int>> B{
    //     {0, 3, 4},
    //     {2, 3, 3},
    //     {0, 1, 9},
    //     {3, 4, 10},
    //     {1, 3, 8}};
    // int C = 4;

    Dijkstra dijk;
    vector<int> result = dijk.solve(A, B, C);
    dijk.print(result);
    return 0;
}