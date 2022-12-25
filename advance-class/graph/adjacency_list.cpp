#include <iostream>
#include <vector>

using namespace std;

class AdjecencyList
{
private:
    void add_edge(vector<vector<int>> &list, int index, int weight, bool directed)
    {
        // cout << "Adding edge: " << index << ", weight: " << weight << endl;
        list[index].push_back(weight);
        if (directed)
        {
            list[weight].push_back(index);
        }
    }

public:
    vector<vector<int>> get_adjacency_list(vector<vector<int>> list, bool directed = false)
    {
        vector<vector<int>> result(list.size() + 1, vector<int>(0, 0));
        for (vector<int> lst : list)
        {
            add_edge(result, lst[0], lst[1], directed);
        }
        return result;
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
};

int main(int argc, const char **argv)
{
    system("clear");
    vector<vector<int>> vect{
        {1, 2},
        {1, 4},
        {2, 5},
        {2, 3},
        {2, 4},
        {5, 3},
        {4, 3}};
    // vector<vector<int>> vect{
    //     {1, 2},
    //     {4, 1},
    //     {2, 4},
    //     {3, 4},
    //     {5, 2},
    //     {1, 3}};
    // vector<vector<int>> vect{
    //     {1, 2},
    //     {2, 3},
    //     {3, 4},
    //     {4, 5}};
    AdjecencyList adjlist;
    adjlist.print(vect);
    vector<vector<int>> result = adjlist.get_adjacency_list(vect, true);
    adjlist.print(result);
    return 0;
}