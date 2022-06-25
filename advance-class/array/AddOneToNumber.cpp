#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &A);
vector<int> plusOneBF(vector<int> &A);
void print(const vector<int> &A, string vn = "");

int main()
{
    system("clear");
    vector<int> A{0, 3, 7, 6, 4, 0, 5, 5, 5}; // {1,2,3}
    print(A, "A");
    vector<int> result = plusOneBF(A);
    // print(result, "result bruit force");
    result = plusOne(A);
    print(result, "result");
    return 0;
}

vector<int> plusOne(vector<int> &A)
{
    reverse(A.begin(), A.end()); // reverse array first
    print(A, "reversed");
    if (A.size() == 1 && A[0] == 0)
        return {A[0] + 1};
    int n = A.size(), sum = 0, cf = 1;

    while (A.size() > 0)
    {
        if (A[A.size() - 1] == 0)
        {
            A.pop_back();
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum = A[i] + cf;
        cf = sum > 9 ? 1 : 0;
        if (cf == 1)
        {
            A[i] = sum % 10;
        }
        else
        {
            A[i] = sum;
        }
    }
    print(A, " ");
    if (cf == 1)
        A.push_back(cf);
    cout << cf << endl;
    reverse(A.begin(), A.end()); // reverse back
    print(A, "reversed back");
    return A;
}

vector<int> plusOneBF(vector<int> &A)
{
    int base = 1, n = A.size(), num = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        num += A[i] * base;
        base *= 10;
    }
    cout << num << endl;
    num += 1;
    vector<int> result;
    while (num > 0)
    {
        int temp = num % 10;
        num = num / 10;
        result.push_back(temp);
    }
    reverse(result.begin(), result.end());

    return result;
}

void print(const vector<int> &A, string vn)
{
    cout << "vector " << vn << " values: " << endl;
    for (auto a : A)
    {
        cout << a << " ";
    }
    cout << endl;
}
