#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>

using namespace std;
vector<int> getCommonElements(vector<int> &A, vector<int> &B);
void printVector(vector<int> &A);
void printHash(unordered_map<int, int> &map);
void printHash(unordered_map<int, vector<int> > &map);
int largestContinuousSequence(vector<int> &A, int B);
int getFibonacci(int n);
int firstRepeating(vector<int> &A);
int minDistance(vector<int> A);
long subarraySum(vector<int> &A);
int Solution::solve(vector<int> &A, int B)
{
    int l = 0;
    int ans = A.size();
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        while (sum > B)
        {
            sum -= A[l];
            l++;
            ans = min(ans, i - l + 1);
        }
    }
    return ans;
}
int main()
{
    /*vector<int> A{1, 2, 2, 1}, B{2, 3, 1, 2};
    vector<int> result = getCommonElements(A, B);*/

    /*vector<int> A{-46, -16, 74, 18, 33, 20, -2, -7, 90, 100, -60, 12, -39, -3, 14, 95, -65, -38, 38, 75, -35, 32, -67, 58, 78, -91, 54, 52, 67, -43, -51, -75, -67, 4, 25, -22, 53, -33};
    int B = 0;

    int result = largestContinuousSequence(A, B);
    cout << "result = " << result << endl; */

    /*int n = 0;
    cout << "enter n: ";
    cin >> n;

    int result = getFibonacci(n);
    for (int i = 1; i < n; i++)
        cout << getFibonacci(i) << " ";
    cout << "result = " << result << endl; */

    /*vector<int> A{8, 15, 1, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3};
    int result = firstRepeating(A);
    cout << "result = " << result << endl; */
    system("clear");
    vector<int> A{1, 2, -2, 4, -4};
    int result = subarraySum(A);
    cout << "result = " << result << endl;
    return 0;
}

long subarraySum(vector<int> &A)
{
    long sumOfAllSubArray = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        int sum = (long)(i + 1) * (n - i) * A[i];
        sumOfAllSubArray += sum;
        cout << "sum = " << sum << ", sumOfAllSubArray = " << sumOfAllSubArray << endl;
    }
    return sumOfAllSubArray;
}

int minDistance(vector<int> A)
{
    int i = 0, minSum = INT_MAX, n = A.size();
    unordered_map<int, int> map;
    printVector(A);
    for (i = 0; i < n; i++)
    {
        int val = A[i];
        if (map.find(val) != map.end()) // found
        {
            int lastIndex = map[val];
            minSum = min(minSum, (i - lastIndex));
        }
        map[val] = i; // store last index
    }
    if (minSum == INT_MAX)
    {
        return minSum;
    }
    cout << minSum << endl;
    printHash(map);
    return -1;
}
int firstRepeating(vector<int> &A)
{
    long i = 0, n = A.size();
    unordered_map<int, int> map;
    int cv = 0, li = INT_MAX;

    printVector(A);

    for (i = 0; i < n; i++)
    {
        cv = A[i];
        if (map.find(cv) != map.end()) // found
        {
            li = min(li, map[cv]);
            cout << "map[" << cv << "] = " << map[cv] << "last index = " << li << endl;
        }
        else
        {

            map[cv] = i;
            cout << "i = " << i << ", cv = " << cv << endl;
        }
    }
    // printHash(map);
    if (li != INT_MAX)
        return A[li];
    return -1;
}

int getFibonacci(int n)
{
    if (n <= 1)
        return n;
    return getFibonacci(n - 1) + getFibonacci(n - 2);
}
int largestContinuousSequence(vector<int> &A, int B)
{
    int i = 0, n = A.size();
    // printVector(A);
    vector<int> result;
    unordered_map<int, int> map;
    for (i = 0; i < n; i++)
    {
        A[i] += A[i - 1];
        cout << " " << A[i] << endl;
        if (map.find(A[i]) != map.end()) // found
        {
            return 1;
        }
        else
        {
            map[i] = 0;
        }
    }
    return 0;
}

vector<int> getCommonElements(vector<int> &A, vector<int> &B)
{
    vector<int> val;
    unordered_map<int, int> map;
    printVector(A);
    printVector(B);

    for (int x : A)
    {
        if (map.find(x) != map.end())
        {
            int num = map[x];
            map[x] = num + 1;
        }
        else
        {
            map[x] = 1;
        }
    }
    printHash(map);
    vector<int> result;
    for (int x : B)
    {
        if (map.find(x) != map.end())
        {
            int num = map[x];
            if (num > 0)
            {
                map[x] = num - 1;
                result.push_back(x);
            }
        }
    }
    cout << endl;
    printHash(map);
    printVector(result);
    return result;
}

void printHash(unordered_map<int, vector<int> > &map)
{
    for (auto it = map.begin(); it != map.end(); it++)
    {
        cout << "key = " << (it->first) << endl;
        printVector(it->second);
    }
    cout << endl;
}

void printHash(unordered_map<int, int> &map)
{
    cout << "value of map: " << endl;
    for (auto x : map)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}
void printVector(vector<int> &A)
{
    cout << "value of vector: " << endl;
    for (int i = 0; i < A.size(); i++)
        cout << "A[" << i << "] = " << A[i] << " ";
    cout << endl;
}
