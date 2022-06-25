#include <iostream>
using namespace std;

void SieveOfEratosthenes(int A);
int main()
{
    system("clear");

    cout << "enter a number ";
    int A;
    cin >> A;
    SieveOfEratosthenes(A);
}

void SieveOfEratosthenes(int A)
{
    int prime[A + 1];
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= A; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
            for (int j = i * i; j <= A; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    cout << endl;
}