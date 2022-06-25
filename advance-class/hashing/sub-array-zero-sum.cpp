#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int findSubArrayWithZeroSum(const vector<int> &A);

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
    vector<int> A{862, -411, -552, -549, 918, 434, 29, -437, 121, -640, -168, -961, 929, -427, 372, 984, 488, -756, 674, -149, 945, 566, 391, -970, -44, 689, -128, -326, 43, -312, 469, 817, -349, 260, 590, -106, -700, 484, -735, -423, 660, 450, -1148, -237, -844, 62, 513, 506, 382, 77, 244, 335};
    // print(A);
    int result = findSubArrayWithZeroSum(A);
    cout << "result = " << result << endl;
    return 0;
}
int findSubArrayWithZeroSum(const vector<int> &A)
{
    int ps = 0;
    set<int> mset;
    for (auto x : A)
    {
        ps += x;
        // cout << "x = " << x << ", ps = " << ps << endl;
        if (ps == 0)
            return 1;
        if (mset.find(ps) != mset.end())
        {
            return 1;
        }
        mset.insert(ps);
    }
    print(mset);
    return 0;
}