#include <iostream>

using namespace std;

int gcd(int A, int B)
{
    int temp;
    while (A > 0)
    {
        temp = A;
        A = B % A;
        B = temp;
    }
    return B;
    // if (B == 0)
    //     return A;
    // return gcd(B, A % B);
}
int main()
{
    int A = 5, B = 17;
    cout << gcd(A, B) << endl;
    return 0;
}
vector<int> maxset(vector<int> A)
{
    vector<int> ls;
    int ln = A.size();

    long sum = 0;
    long msum = 0;
    int ind = 0;
    int sind = 0;
    int eind = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if ((sum + A[i]) > msum)
        {
            sind = ind;
            eind = i + 1;
            msum = sum + A[i];
            sum = sum + A[i];
        }
        else if ((sum + A[i]) == msum && (eind - sind) < (i - ind + 1))
        {
            sind = ind;
            eind = i + 1;
        }
        else if (A[i] < 0)
        {
            sum = 0;
            ind = i + 1;
        }
        else
        {
            sum += A[i];
        }
    }
    for (int i = sind; i < eind; i++)
    {
        ls.push_back(A[i]);
    }

    return ls;
}
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    int size = intervals.size();
    for (int i = 0; i < size; i++)
    {
        Interval current = intervals[i];
        if (newInterval.start > current.end)
        {
            ans.push_back(current);
        }
        else if (newInterval.end < current.start)
        {
            ans.push_back(newInterval);
            for (int j = i; j < size; j++)
            {
                ans.push_back(intervals[j]);
            }
            return ans;
        }
        else
        {
            newInterval.start = min(newInterval.start, current.start);
            newInterval.end = max(newInterval.end, current.end);
        }
    }
    ans.push_back(newInterval);
    return ans;
}

long long power(long long a, long long n, long long m)
{
    if (n == 0)
    {
        return 1 % m;
    }
    long long hp = power(a, n / 2, m);
    long long ha = ((hp % m) * (hp % m)) % m;
    if ((n & 1) == 0)
    {
        return ha;
    }
    else
    {
        return ((ha % m) * a % m) % m;
    }
}

int solve(int A, int B)
{
    long long fact = 1;
    long long mod = 1000000006;
    for (long i = 1; i <= B; i++)
    {
        fact = (fact % mod * (i % mod)) % mod;
    }
    mod++;
    // cout<<fact<<endl;
    return power(A, fact, mod) % mod;
}

int cntBits(vector<int> &A)
{
    int n = A.size(), mod = 1e9 + 7;
    long bitsCount = 0, result = 0;
    for (int b = 0; b < 32; b++)
    {
        bitsCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] & (1 << b))
                bitsCount++;
        }
        long unsetBitCount = n - bitsCount;
        long totalPairs = bitsCount * unsetBitCount * 2;
        result = (result + totalPairs % mod) % mod;
    }
    return result;
}

int solve(vector<int> &A, int B)
{
    int totalSmallerNums = 0, n = A.size();
    for (int i = 0; i < n; ++i)
    {
        if (A[i] <= B)
            totalSmallerNums++;
    }
    int current = 0, left = 0, right = 0, answer = totalSmallerNums;
    while (right < n)
    {
        if (A[right] <= B)
        {
            curCount++;
        }
        right += 1;
        if (right - left < totalSmallerNums)
        {
            continue;
        }

        ans = min(ans, totalSmallerNums - current);

        if (A[left] <= B)
        {
            current -= 1;
        }
        left++;
    }
    return answer;
}

int olve(vector<int> &A)
{
    int n = A.size(), i = 0, swaps = 0;
    while (i < n)
    {
        if (A[i] == i)
        {
            i += 1;
        }
        else
        {
            swap(A[i], A[A[i]]);
            swaps += 1;
        }
    }
    return swaps;
}