#include <iostream>

using namespace std;
/**
 * @brief Find the smalles prime factor between 1 to n-2
 *
 * @return int[]
 */
int *smallestPrimeFactor(int A);

int main()
{
    return 0;
}
int power(int a, int n, int m)
{
    if (n == 0)
    {
        return 1;
    }
    long hp = power(a, n / 2, m);
    long ha = ((hp % m) * (hp % m)) % m;
    if (n % 2 == 0)
    {
        return ha;
    }
    else
    {
        return ((ha % m) * a % m) % m;
    }
}
int *smallestPrimeFactor(int A)
{
    int spf[A + 1];
    spf[0] = spf[1] = -1;
    for (int i = 0; i <= A; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= A; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= A; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}