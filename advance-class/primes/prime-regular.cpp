#include <iostream>

using namespace std;

bool isPrime(int A)
{
    if (A == 1)
        return false;
    for (int i = 2; i * i <= A; i++)
    {
        if (A % i == 0)
            return false;
    }
    return true;
}
int main()
{
    system("clear");
    cout << "enter a number: ";
    int A;
    cin >> A;
    for (int i = 1; i < A; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
    return 0;
}