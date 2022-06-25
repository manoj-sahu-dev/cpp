#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <unordered_map>

using namespace std;
int slidingWindowsHousing(vector<int> &A, int B);
int diffPossible(const vector<int> &A, int B);
vector<int> twoSum(const vector<int> &A, int B);
vector<int> subarrayWithGivenSum(vector<int> A, int B);

int changeCharacter(string A, int B);

vector<int> slidingWindowBiggestInt(vector<int> &nums, int k);
int findMax(vector<int> &A, int s, int e);

void print(vector<int> &A);
void print(unordered_map<int, int> &map);
void print(set<int> &A);

int main()
{
    system("clear");

    /*vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    print(nums);
    int size = 3;
    vector<int> result = slidingWindowBiggestInt(nums, size);
    print(result);*/

    /*string A;
    int B;
    cout << "enter a string: ";
    cin >> A;

    cout << "enter max char to replace: ";
    cin >> B;

    int result = changeCharacter(A, B);

    cout << "result = " << result << endl; */
    vector<int> A{62, 23, 50, 44, 6, 39, 15, 44, 27, 47, 29, 30, 44, 28, 42, 7, 32, 16, 40, 8, 7, 5, 48, 48, 16, 9, 5, 50, 16, 18, 9, 21, 26, 48, 37, 27, 7, 5, 29, 24, 28, 10, 44, 21, 1, 48, 15, 31, 41, 42, 23, 4, 32, 40, 40, 27, 20, 29, 42, 25, 18, 37, 43, 13, 30, 42, 24, 17, 42, 14, 42, 43, 36, 31, 29, 24, 24, 8, 3, 12, 34, 14, 6};
    int B = 62;
    print(A);
    int result = slidingWindowsHousing(A, B);
    unordered_map<int, int> map;
    cout << map[10] << endl;
    cout << "result = " << result << endl;

    return 0;
}

int slidingWindowsHousing(vector<int> &A, int B)
{
    int i = 0, n = A.size(), j = 0, currentSum = 0;

    while (j < n)
    {
        currentSum += A[j];
        j += 1;

        while (currentSum > B and i < j)
        {
            currentSum -= A[i];
            i += 1;
        }

        if (currentSum == B)
        {
            cout << "i = " << A[i] << ", j = " << A[j - 1] << endl;
            vector<int> res;
            for (int m = i; m < j; m++)
            {
                res.push_back(A[m]);
            }
            print(res);
        }
    }
    return 0;
}
int diffPossible(const vector<int> &A, int B)
{
    int i = 0, n = A.size(), diff = 0, diff2 = 0;
    set<int> mset;
    for (i = 0; i < n; i++)
    {

        diff = (A[i] - B);
        diff2 = A[i] + B;

        cout << "diff: " << diff << ", diff2: " << diff2 << endl;

        if (mset.find(diff) != mset.end() || mset.find(diff2) != mset.end())
        {
            cout << "\n-----diff = " << diff << endl;
            // return true;
        }
        mset.insert(A[i]);
        print(mset);
        for (int j = i + 1; j < n; j++)
        {
            cout << "A[" << i << "] = " << A[i] << ", A[" << j << "] = " << A[j] << ", diff = " << (A[i] - A[j]) << endl;
            if (abs(A[i] - A[j]) == B)
            {
                cout << "found--------------------------------";
                return 1;
            }
        }
    }
    return false;
}
vector<int> subarrayWithGivenSum(vector<int> A, int B)
{
    int n = A.size();
    int start = -1, sum = 0;
    // while (sum > B && start < (i - 1))
    // {
    // }
    return {};
}
vector<int> twoSum(const vector<int> &A, int B)
{
    int n = A.size();
    int idx1 = -1, idx2 = INT_MAX, ntf = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n - 1; i++)
    {
        int val = A[i];
        ntf = B - val; // no to find
        cout << "A[" << i << "] = " << val << ", no to find = " << ntf << endl;
        print(map);

        if (map.find(ntf) != map.end()) // found
        {
            cout << "found solution -> ";
            print(map);
            for (int j = i + 1; j < n; j++)
            {
                if (A[j] == ntf)
                    return {i, j + 1};
            }
        }
        else
        {
            map.clear();
            map[ntf] = i;
        }
    }
    if (idx1 == -1)
        return {};
    return {idx1, idx2};
}
int changeCharacter(string A, int B)
{
    int characters[26];
    for (int i = 0; i < 26; i++)
        characters[i] = 0;
    for (int i = 0; i < A.length(); i++)
    {
        int num = A[i] - 'a';
        characters[num]++;
        cout << num << endl;
    }
    sort(characters, characters + 26);

    for (int i = 0; i < 26; i++)
    {
        if (characters[i] != 0)
        {
            if (B > 0 && B >= characters[i])
            {
                B -= characters[i];
            }
            else
            {
                return 26 - i;
            }
        }
    }
    return 0;
}

vector<int> slidingWindowBiggestInt(vector<int> &nums, int k)
{
    vector<int> result;
    int i = 0, n = nums.size(), j = k, maxNum = INT_MIN;
    int finalIndex = n - j + 1;
    cout << "i = " << i << ", j = " << j << ", finalIndex = " << finalIndex << endl;
    while (i < finalIndex)
    {
        result.push_back(findMax(nums, i, j));
        i++;
        j++;
    }
    return result;
}

string solve(string A, string B)
{
    int i = 0, j = 0, aSize = A.size(), bSize = B.size();
    while (j < bSize)
    {
        if (A[i] == B[j])
        {
            j++;
            i++;
        }
        j++;
        if (i == aSize)
            return "YES";
    }
    return "NO";
}

int findMax(vector<int> &A, int s, int e)
{
    int maxnum = INT_MIN;
    for (int i = s; i < e; i++)
    {
        maxnum = max(maxnum, A[i]);
    }
    return maxnum;
}
void print(vector<int> &A)
{
    cout << "\ncontent of vector: ";
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

void print(unordered_map<int, int> &map)
{
    cout << "value of map: " << endl;
    for (auto x : map)
    {
        cout << "{ " << x.first << " , " << x.second << " }  ";
    }
    cout << endl;
}
void print(set<int> &A)
{
    cout << "set >> : ";
    for (auto c : A)
        cout << c << " ";
    cout << endl;
}