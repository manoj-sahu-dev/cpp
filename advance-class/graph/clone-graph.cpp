#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

UndirectedGraphNode *clone(UndirectedGraphNode &node, map<UndirectedGraphNode, UndirectedGraphNode> &_map)
{
    return NULL;
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
    map<UndirectedGraphNode, UndirectedGraphNode> _map;
    return clone(node, _map);
}

int main(int argc, char const *argv[])
{

    return 0;
}
