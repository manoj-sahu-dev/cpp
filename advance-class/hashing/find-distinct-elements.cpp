#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int distinctElements(const vector<int> &A);

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

int main(int argc, char **argv)
{
    system("clear");
    vector<int> A{1, 1, 3, 4, 5, 5, 3, 7, 9, 4};
    int result = distinctElements(A);
    cout << result << endl;
    return 0;
}
int distinctElements(const vector<int> &A)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < A.size(); i++)
    {
        umap[A[i]] = A[i];
    }
    return umap.size();
}