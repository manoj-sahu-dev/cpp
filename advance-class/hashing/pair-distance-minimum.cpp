#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int findMinimumDistance(const vector<int> &A);

void print(unordered_map<int, int> &map)
{
    cout << "map size: " << map.size() << ", content: " << endl;
    for (auto x : map)
    {
        cout << " {" << x.first << ", " << x.second << "} ";
    }
    cout << endl;
}
void print(vector<int> &A)
{
    cout << "content of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}
void print(set<char> &A)
{
    cout << "set >> : ";
    for (char c : A)
        cout << c << " ";
    cout << endl;
}

void print(set<int> &A)
{
    cout << "set >> : ";
    for (auto c : A)
        cout << c << " ";
    cout << endl;
}

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{1, 1};
    // print(A);
    int result = findMinimumDistance(A);
    cout << "result = " << result << endl;
    return 0;
}
int findMinimumDistance(const vector<int> &A)
{
    unordered_map<int, int> umap;
    int distance = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        if (umap.find(A[i]) != umap.end()) // found
        {
            cout << i << " , Found " << A[i] << " , at " << umap[A[i]] << endl;
            distance = min(distance, i - umap[A[i]]);
        }
        umap[A[i]] = i;
    }
    print(umap);
    return distance == INT_MAX ? -1 : distance;
}