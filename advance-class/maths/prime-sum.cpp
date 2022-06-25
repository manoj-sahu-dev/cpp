#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Given an even number A ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.
 *
 * If there is more than one solution possible, return the lexicographically smaller solution.
 *
 * If [a, b] is one solution with a <= b, and [c,d] is another solution with c <= d, then
 * [a, b] < [c, d], If a < c OR a==c AND b < d.
 * NOTE: A solution will always exist. Read Goldbach's conjecture.
 *
 * @param A
 * @return vector<int>
 */
vector<int> primesum(int A);
vector<long long> sieveOfEratosthenes(int A);

void print(vector<int> A)
{
    cout << "content of vector: ";
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

int main(int argc, char **argv)
{
    system("clear");
    int n;
    cout << "enter a number: ";
    cin >> n;
    vector<int> ans = primesum(n);
    print(ans);
    return 0;
}

vector<int> primesum(int A)
{
    vector<int> res;

    vector<long long> soe = sieveOfEratosthenes(A);
    for (int i = 2; i <= A; i++)
    {
        if (soe[i] && soe[A - i])
        {
            res.push_back(i);
            res.push_back(A - i);
            return res;
        }
    }
    // print(soe);

    // int low = 0, high = soe.size() - 1;
    // while (low <= high)
    // {
    //     int sum = soe[low] + soe[high];
    //     cout << "low " << low << ", high " << high << ", sum " << sum << endl;
    //     if (sum == A)
    //     {
    //         res.push_back(soe[low]);
    //         res.push_back(soe[high]);
    //         return res;
    //     }
    //     else if (sum < A)
    //     {
    //         low += 1;
    //     }
    //     else
    //     {
    //         high -= 1;
    //     }
    // }
    res.push_back(0);
    return res;
}

vector<long long> sieveOfEratosthenes(int A)
{
    vector<long long> res(A + 1, 0);

    // vector<int> soe;

    for (int i = 2; i <= A; i++)
    {
        if (res[i] == 0)
        {
            for (long long j = i * i; j <= A; j += i)
            {
                cout << j << " ";
                res[j] = 1;
            }
        }
    }
    return res;
}