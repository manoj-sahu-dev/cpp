#include <iostream>
#include <unordered_map>

using namespace std;

int getAnagramCount(string A, string B);
void print(unordered_map<char, int> umap)
{
    for (auto x : umap)
    {
        cout << x.first << " : " << x.second << ", ";
    }
    cout << endl;
}
bool isSame(unordered_map<char, int> amap, unordered_map<char, int> bmap)
{
    for (auto x : amap)
    {
        char c = x.first;
        int o = x.second;
        if (amap[c] != bmap[c])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    system("clear");
    string A = "docp";
    string B = "aoapeooeoapcpaocecddoocdcqqapeapccc";
    int result = getAnagramCount(A, B);
    cout << "no of anagram in string is : " << result << endl;

    return 0;
}
int getAnagramCount(string A, string B)
{
    int count = 0;
    unordered_map<char, int> aMap;
    unordered_map<char, int> bMap;

    for (auto x : A)
    {
        aMap[x] += 1;
    }
    print(aMap);
    cout << "--------------------------------" << endl;

    int aCount = A.length(), bCount = B.length(), i = 0, j = aCount;
    for (int i = 0; i < j; i++)
    {
        char c = B[i];
        bMap[c] += 1;
    }
    print(bMap);
    if (isSame(aMap, bMap))
    {
        count++;
    }
    cout << "i = " << i << ", j = " << j << ", count = " << count << endl;

    while (j < bCount)
    {
        char c = B[i];
        bMap[c]--;
        if (bMap[c] == 0)
        {
            bMap.erase(c);
        }
        char d = B[j];
        bMap[d]++;
        cout << "i = " << i << ", j = " << j << ", erase = " << c << ", insert = " << d << ", count = " << count << endl;
        print(bMap);
        i += 1;
        j += 1;
        // d o c p
        // a o a p e o o e o a p c p a o c e c d d o o c d c q q a p e a p c c c
        if (isSame(aMap, bMap))
        {
            count++;
        }
    }
    return count;
}