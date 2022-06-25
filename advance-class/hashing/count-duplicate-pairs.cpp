#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int countDuplicatePairs(const vector<int> &A);

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
    return 0;
}
int countDuplicatePairs(const vector<int> &A)
{
    return 0;
}