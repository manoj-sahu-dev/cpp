#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
int pairWithXoR(vector<int> &A, int B);
vector<int> subarraySum(vector<int> &nums, int k);
int diffPossible(const vector<int> &A, int B);
vector<int> twoSum(const vector<int> &A, int B);
vector<int> findPairsForTargetSum(vector<int> &A, int B);
vector<int> findPairsForTargetSumBF(vector<int> &A, int B);

void print(vector<int> &A);
void print(unordered_map<int, int> &A);

int main()
{
    system("clear");

    /*vector<int> A{8, 9, 1, -2, 4, 5, 11, -6, 7, 5};
    print(A);
    int B = 11;
    vector<int> result = findPairsForTargetSumBF(A, B);
    print(result);
    result = findPairsForTargetSum(A, B);
    print(result); */

    vector<int> A{3, 6, 8, 10, 15, 50};
    print(A);
    int B = 1;
    cin >> B;
    int result = pairWithXoR(A, B);
    cout << result << endl;
    return 0;
}

int pairWithXoR(vector<int> &A, int B)
{
    int n = A.size(), result = 0;

    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {

        int curr_xor = B ^ A[i];
        cout << "xor " << curr_xor << ", A[" << A[i] << "] = " << A[i] << endl;
        if (map.find(curr_xor) != map.end())
        {
            result += 1;
        }
        if (map.find(A[i]) == map.end())
        {
            map[A[i]] = i;
        }
        print(map);
    }
    return result;
}

vector<int> subarraySum(vector<int> &A, int B)
{
    int start = 0, i = 0, n = A.size();
    long currentSum = A[0];

    for (int i = 1; i <= n; i++)
    {
        while (currentSum > B && start < (i - 1))
        {
            currentSum -= A[start];
        }

        if (currentSum == B)
        {
            cout << "A[" << start << "] = " << A[start] << ", A[" << i << "] = " << A[i] << endl;
            // return {start, (i - 1)};
        }
        if (i < n)
        {
            currentSum += A[i];
        }
    }
    return {-1};
}

int diffPossible(const vector<int> &A, int B)
{
    return 0;
}

vector<int> twoSum(const vector<int> &A, int B)
{
    set<int> ms;
    for (int i = 0; i < A.size(); i++)
    {
        int target = B - A[i];
        if (ms.find(target) != ms.end())
        {
            cout << "--> i = " << i << " target = " << target << endl;
            for (int j = 0; j < i; j++)
            {
                if (A[j] == target)
                {
                    cout << "i = " << i << " target = " << target << ", j = " << j << endl;
                    return {j + 1, i + 1};
                }
            }
        }
        ms.insert(A[i]);
    }
    return {};
}
vector<int> findPairsForTargetSum(vector<int> &A, int B)
{
    int i = 0, n = A.size(), target = 0;
    unordered_map<int, int> map;

    for (i = 0; i < n; i++)
    {
        target = A[i];
        if (map.find(target) != map.end())
        {
            map[target] += 1;
        }
        else
        {
            map[target] = 1;
        }
    }
    print(map);
    for (i = 0; i < n; i++)
    {
        target = B - A[i];

        if (target == B)
        {
            if (map.find(target) != map.end())
            {
                if (map[target] > 1)
                    cout << "\nfound at i = " << i << " target = " << target << ", map = " << map[target] << endl;
            }
        }
        else if (map.find(target) != map.end())
        {
            cout << "\nfound at i = " << i << " target = " << target << ", map = " << map[target] << endl;
        }
    }
    return {};
}
vector<int> findPairsForTargetSumBF(vector<int> &A, int B)
{
    int i = 0, j = 0, n = A.size(), target = 0;
    for (int i = 0; i < n - 1; i++)
    {
        target = B - A[i];
        cout << "i = " << i << " target = " << target << endl;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] == target)
            {
                cout << "i = " << i << " j = " << j << endl;
                return {A[i], A[j]};
            }
        }
    }
    return {};
}
void print(vector<int> &A)
{
    cout << "content of vector: ";
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