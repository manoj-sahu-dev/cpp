#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

int findAthMagicalNumber(int A, int B, int C);
int countMagicalNumber(int B, int C, int M);
int findGCD(int X, int Y);
int main(int argc, char **argv)
{
    system("clear");

    int A = 8;
    int B = 2;
    int C = 3;
    int result = findAthMagicalNumber(A, B, C);
    cout << result << endl;

    return 0;
}
int findAthMagicalNumber(int A, int B, int C)
{
    int ans = 0;
    int low = min(B, C), high = min(B, C) * A, mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (countMagicalNumber(B, C, mid) < A)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int findGCD(int X, int Y)
{
    if (X == 0)
        return Y;
    return findGCD(Y % X, X);
}

int countMagicalNumber(int B, int C, int M)
{
    int midB = M / B;
    int midC = M / C;
    return (midB + midC - ((M * findGCD(B, C)) / (B * C)));
}