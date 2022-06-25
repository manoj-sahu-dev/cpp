#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

vector<int> findLargestDistanceSumZero(const vector<int> &A);

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
    vector<int> A{-19, 8, 2, -8, 19, 5, -2, -23};
    print(A);
    vector<int> result = findLargestDistanceSumZero(A);
    print(result);
    return 0;
}
vector<int> findLargestDistanceSumZero(const vector<int> &A)
{
    unordered_map<int, int> umap;
    int distance = INT_MIN, prefixSum = 0, start = 0, end = -1;
    vector<int> result;
    for (int i = 0; i < A.size(); i++)
    {
        prefixSum += A[i];
        cout << prefixSum << endl;
        if (prefixSum == 0)
        {
            start = 0;
            end = i;
            distance = i + 1;
        }
        if (umap.find(prefixSum) != umap.end()) // found
        {
            int temp = max(distance, i - umap[prefixSum]);

            if (temp > distance)
            {
                distance = temp;
                end = i;
                start = end - distance + 1;
            }
        }
        else
        {
            umap[prefixSum] = i;
        }
    }
    print(umap);
    cout << "start: " << start << " end: " << end << endl;
    for (int i = start; i <= end; i++)
        result.push_back(A[i]);

    return result;
}