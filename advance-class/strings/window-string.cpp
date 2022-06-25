#include <iostream>
#include <unordered_map>

using namespace std;

void print(unordered_map<char, int> amap)
{
    for (auto chars : amap)
    {
        cout << chars.first << " : " << chars.second << ", ";
    }
    cout << endl;
}
/**
 * @brief check two maps & compares their content
 *
 * @param aset
 * @param bset
 * @return true
 */
bool isSame(unordered_map<char, int> aset, unordered_map<char, int> bset);

/**
 * @brief Given a string A and a string B, find the window with minimum length in A, which will contain all the characters in B in linear time complexity.
 * Note that when the count of a character c in B is x, then the count of c in the minimum window in A should be at least x.
 *
 * Note:
 *
 * If there is no such window in A that covers all characters in B, return the empty string
 * If there are multiple such windows, return the first occurring minimum window ( with minimum start index and length )
 *
 * @param A
 * @param B
 * @return string
 */
string getWindowString(string A, string B);

int main(int argc, char **argv)
{
    system("clear");

    string A = "ADOBECODEBANC";
    string B = "ABC";
    string ans = getWindowString(A, B);
    cout << "max window string = " << ans << endl;
    return 0;
}

string getWindowString(string A, string B)
{
    string ans;
    unordered_map<char, int> amap, bmap;
    int i = 0, n = B.size(), j = n;

    for (int i = 0; i < n; i++)
    {
        char ch = B[i];
        bmap[ch] += 1;
    }
    print(bmap);

    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        amap[ch] += 1;
    }
    print(amap);

    while (j < n)
    {
        j += 1;
    }
    return ans;
}

bool isSame(unordered_map<char, int> amap, unordered_map<char, int> bmap)
{
    for (auto x : amap)
    {
        char c = x.first;
        if (amap[c] != bmap[c])
        {
            return false;
        }
    }
    return true;
}