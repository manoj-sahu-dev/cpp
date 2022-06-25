// file - recursion.cpp
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> getGreyCode(int A);
int isMagic(int A);
int tileFill(int A);
int pow(int A, int B, int C);
int power(int A, int B);
void reverseString(string &A, int lastChar);

bool palindrome(string A, int start, int end);
void print(int A);
int fibo(int A);
int factorial(int A);
int sumOfFirstXNumber(int A);
int bar(int x, int y);
int foo(int x, int y);
int sumOfDigit(int A);
int fun(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return fun(x * x, n / 2);
    else
        return x * fun(x * x, (n - 1) / 2);
}

int main()
{
    system("clear");

    // cout << "enter a string : ";
    // cin >> A;
    // reverseString(A, A.length());
    // cout << n << endl;
    // int result = fibo(A);
    // cout << result << endl;
    // cout << "power = " << power(2, 10) << endl;
    // cout << "fast power = " << fastPower(2, 10) << endl;
    int n;
    cin >> n;
    vector<int> A = getGreyCode(n);
    cout << "content of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
    // cout << (3 & 1) << endl;
    return 0;
}

vector<int> getGreyCode(int A)
{
    vector<int> result = {0};

    int resultSize = 1;
    for (int i = 0; i < A; i++)
    {
        resultSize = result.size();
        for (int j = resultSize - 1; j >= 0; j--)
        {
            result.push_back(result[j] + (1 << i));
        }
    }
    return result;
}

int isMagic(int A)
{
    int num = sumOfDigit(A);
    cout << "A = " << A << ", num = " << num << endl;
    if (num < 10)
    {
        cout << "returning num: " << num << endl;
        if (num == 1)
            return 1;
        return 0;
    }

    return isMagic(num);
}
int tileFill(int A)
{
    if (A <= 3)
        return 1;
    return tileFill(A - 1) + tileFill(A - 4);
}
int pow(int A, int B, int C)
{
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    long mod;
    if (B & 1)
    {
        mod = A % C;
        mod = (mod * pow(A, B - 1, C) % C) % C;
    }
    else
    {
        mod = pow(A, B / 2, C);
        mod = (mod * mod) % C;
    }

    return (mod + C) % C;
    // if (B == 0)
    //     return 1;

    // int subPower = fastPower(A, B / 2);
    // int subPowerSquare = subPower * subPower;

    // if (B & 1)
    //     return A * subPowerSquare;
    // return subPowerSquare;
}

int power(int A, int B)
{
    if (B == 0)
        return 1;
    return A * power(A, B - 1);
}
int sumOfDigit(int A)
{
    if (A == 0)
    {
        return A;
    }
    return A % 10 + sumOfDigit(A / 10);
}

void reverseString(string &A, int lastChar)
{
    if (lastChar < 0)
        return;

    cout << A[lastChar];
    return reverseString(A, lastChar - 1);
}

int bar(int x, int y)
{
    if (y == 0)
        return 1;
    return (x + bar(x, y - 1));
}
int foo(int x, int y)
{
    if (y == 0)
        return 0;
    return bar(x, foo(x, y - 1));
}
void printreverse(string S)
{
    if (S.size() == 0)
    {

        return;
    }

    printreverse(S.substr(1));

    cout << S[0];
}

bool palindrome(string A, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    else
    {
        if (A[start] == A[end])
            return palindrome(A, start + 1, end - 1);
        else
            return false;
    }
}
void print(int A)
{
    if (A == 0)
        return;
    cout << A << endl;

    print(A - 1);
}
int fibo(int A)
{
    if (A == 1)
        return 0;
    if (A == 2)
        return 1;
    return fibo(A - 1) + fibo(A - 2);
}
int sumOfFirstXNumber(int A)
{
    if (A == 1)
        return A;
    return A + sumOfFirstXNumber(A - 1);
}

int factorial(int A)
{
    if (A == 0)
        return 1;
    return A * factorial(A - 1);
}