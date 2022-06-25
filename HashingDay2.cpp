#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>
#include <unordered_map>

using namespace std;
int checkPalindrome(string A);

int getSum(int A, int B, vector<int> &C);

vector<int> longestContinuousSubArrayZeroSecond(vector<int> &A);
vector<int> longestContinuousSubArrayZero(vector<int> &A);
vector<int> slidingWindowBF(vector<int> &A, int B);

vector<int> continuousSubArrayTargetSumBF(vector<int> &A, int B);
int colorfull(int A);
vector<int> reverseVector(vector<int> &A);
vector<int> createVector(int num);
void print(vector<int> &A);
void print(unordered_map<int, int> &map);
void print(set<char> &A);
int main()
{

    system("clear");
    /*int n;
    cout << "enter a num: ";
    cin >> n;

    int color = colorfull(n);
    cout << "color: " << color << endl;*/
    /*vector<int> A{1, 2, 3, 4, 5};
    int target = 5;
    vector<int> result = continuousSubArrayTargetSumBF(A, target);
    print(result);*/

    /*vector<int> A{1, 2, 1, 3, 4, 3};
    print(A);
    int target = 3;
    vector<int> result = slidingWindowBF(A, target);
    print(result); */

    /*vector<int> A = {-19, 8, 2, -8, 19, 5, -2, -23}; //{1, 2, -2, 4, -4};
    print(A);
    vector<int> result = longestContinuousSubArrayZeroSecond(A);
    cout << "\nresult = " << endl;
    print(result);*/

    /*string A;
    cin >> A;
    int result = checkPalindrome(A);
    cout << result << endl;*/

    int A = 5, B = 2;
    vector<int> C = {0, 0, 1};
    print(C);
    int result = getSum(A, B, C);
    cout << "result = " << result << endl;
    return 0;
}

int getSum(int A, int B, vector<int> &C)
{
    unordered_map<int, int> map;
    int n = C.size();
    for (int i = 0; i < n; i++)
    {
        int val = C[i];
        if (map.find(val) != map.end())
        {
            map[val] += 1;
        }
        else
        {
            map[val] = 1;
        }
        print(map);
    }
    long sum = 0;
    int found = 1;
    for (auto x : map)
    {
        if (x.second >= B)
        {
            found = 0;
            sum += x.first;
            cout << " {" << x.first << ", " << x.second << "} "
                 << ", sum = " << sum << endl;
        }
    }
    return found == 1 ? -1 : (sum % (10 ^ 9 + 7));
}

int checkPalindrome(string A)
{
    set<char> mset;
    for (int i = 0; i < A.length(); i++)
    {
        if (mset.find(A[i]) != mset.end())
        {
            mset.erase(A[i]);
        }
        else
        {
            mset.insert(A[i]);
        }
        print(mset);
    }
    return mset.size() < 2 ? 1 : 0;
}

vector<int> longestContinuousSubArrayZeroSecond(vector<int> &A)
{
    vector<int> result;
    unordered_map<int, int> map;
    int i = 0, n = A.size(), start = -1, end = -1, sum = 0, maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        cout << "sum = " << sum << endl;
        if (sum == 0)
        {
            maxlen = i + 1;
            start = 0;
            end = i;
        }

        if (map.find(sum) != map.end()) // found
        {
            int temp = max(maxlen, i - map[sum]);
            if (temp > maxlen)
            {
                maxlen = temp;
                start = i - maxlen + 1;
            }
        }
        else
        {
            map[sum] = i;
        }
        print(map);
    }

    if (start != -1)
    {
        end = start + maxlen;
        for (i = start; i < end; i++)
        {
            result.push_back(A[i]);
        }
    }
    return result;
}

vector<int> longestContinuousSubArrayZero(vector<int> &A)
{
    unordered_map<int, int> map;
    int n = A.size(), sum = 0, maxlen = 0, start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (A[i] == 0 && maxlen == 0)
            maxlen = 1;
        if (sum == 0)
            maxlen = i + 1;
        // cout << "start " << i << endl;
        if (map.find(sum) != map.end()) // found
        {
            // cout << "start 1" << endl;
            int temp = max(maxlen, i - map[sum]);
            if (temp > maxlen)
            {
                cout << "start 2" << endl;
                maxlen = temp;
                end = i;
                start = end - maxlen + 1;
                cout << ">>>>> i = " << i << ", sum = " << sum << ", map = " << map[sum] << ", ne = " << (i - map[sum]) << endl;
            }
        }
        else
        {
            cout << "else sum = " << sum << endl;
            map[sum] = i;
            if (sum == 0)
                end = i;
        }
    }
    vector<int> result;
    cout << "start = " << start << " end = " << end << " maxlen = " << maxlen << endl;
    if (start != end)
        for (int i = start; i <= end; i++)
            result.push_back(A[i]);
    return result;
    /*vector<int> result;
    int n = A.size(), maxlen = 0;
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            if (sum == 0)
            {
                int temp = max(maxlen, j - i + 1);
                if (temp > maxlen)
                {
                    result.clear();

                    maxlen = temp;
                    cout << "i = " << i << ", j = " << j << ", maxlen = " << maxlen << endl;
                    for (int k = i; k <= (j); k++)
                    {
                        result.push_back(A[k]);
                    }
                }
            }
        }
        cout << "sum = " << sum << ", maxlen = " << maxlen << endl;
    }
    return result;
    */
}
vector<int> slidingWindowBF(vector<int> &A, int B)
{
    int n = A.size();
    if (B > n)
        return {};
    vector<int> result;
    int left = 1, right = B;
    unordered_map<int, int> map;
    for (int j = 0; j < B; j++)
    {
        int val = A[j];
        if (map.find(val) != map.end()) // found
        {
            map[val] += 1;
        }
        else
        {
            map[val] = 1;
        }
    }
    print(map);
    result.push_back(map.size());
    while (right < n)
    {
        int nextVal = A[right];
        int preVal = A[left - 1];
        // cout << "left = " << left << ", preVal: " << preVal << " right = " << right << ", nextVal: " << nextVal << endl;
        if (map.find(nextVal) != map.end()) // found
        {
            map[nextVal] += 1;
        }
        else
        {
            map[nextVal] = 1;
        }

        if (map.find(preVal) != map.end()) // found
        {
            map[preVal] -= 1;
            if (map[preVal] == 0)
            {
                map.erase(preVal);
            }
        }
        print(map);
        left += 1;
        right += 1;
        result.push_back(map.size());
    }
    // result.push_back(map.size());
    // while (right < n)
    // {
    //     set<int> s;
    //     for (int j = left; j <= right; j++)
    //     {
    //         s.insert(A[j]);
    //         // cout << A[j] << " ";
    //     }
    //     result.push_back(s.size());
    //     right += 1;
    //     left += 1;
    //     // cout << s.size() << " " << endl;
    // }

    /*
for (int i = 0; i <= (n - B); i++)
{
    set<int> s;
    cout << "n = " << n << ", i = " << i << "   ---->  ";
    for (int j = i; j < (i + B); j++)
    {
        s.insert(A[j]);
        cout << A[j] << " ";
    }
    result.push_back(s.size());
    cout << s.size() << " " << endl;
}
*/

    return result;
}

vector<int> continuousSubArrayTargetSumBF(vector<int> &A, int B)
{
    int i = 0, j = 0, n = A.size();

    for (i = 0; i < n; i++)
    {
        int sum = 0;
        vector<int> sa;

        for (j = i + 1; j < n; j++)
        {

            sum += A[j];
            sa.push_back(A[j]);
            if (sum == B)
            {
                cout << "   << " << i << " , " << j << " ";
                return sa;
            }
            cout << endl;
        }
    }
    return {-1};
}

int colorfull(int A)
{
    cout << "n = " << A << endl;
    vector<int> vec = createVector(A);
    print(vec);
    vec = reverseVector(vec);
    print(vec);

    set<int> s;

    int n = vec.size(), product = 0;

    for (int i = 0; i < n; i++)
    {
        product = 1;
        for (int j = i; j < n; j++)
        {
            product *= vec[j];
            if (s.find(product) != s.end()) // found
            {
                return 0;
            }
            s.insert(product);
        }
    }
    return 1;
}

vector<int> createVector(int num)
{
    vector<int> A;
    while (num > 0)
    {
        A.push_back(num % 10);
        num /= 10;
    }
    return A;
}
vector<int> reverseVector(vector<int> &A)
{
    int i = 0, left = 0, n = A.size(), right = n - 1;

    while (left < right)
    {
        int temp = A[right];
        A[right] = A[left];
        A[left] = temp;
        left++;
        right--;
    }
    return A;
}
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