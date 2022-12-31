#include <bits/stdc++.h>

using namespace std;

/**
 * @brief You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order).
 * You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
 *
 * @param kArrays
 * @param k
 * @return vector<int>
 */
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    cout << "number of arrays: " << k << endl;
    // Write your code here.
}

void print(vector<int> &v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}
void print(vector<vector<int>> &v)
{
    for (auto x : v)
    {
        print(x);
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    system("clear");
    vector<vector<int>> kArrays{
        {1, 5, 9},
        {45, 90},
        {2, 6, 78, 100, 234},
        {0}};
    print(kArrays);
    vector<int> result = mergeKSortedArrays(kArrays, kArrays.size());
    return 0;
}
