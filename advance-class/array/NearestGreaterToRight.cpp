#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nearestGreaterInRight(vector<int> &A);
vector<int> nearestGreaterInRightBruiteForces(vector<int> &A);
void print(const vector<int> &A, string vn);

int main()
{
    system("clear");
    vector<int> A{1, 3, 0, 0, 1, 2, 4};
    print(A, "A");
    vector<int> result = nearestGreaterInRight(A); // nearestGreaterInRightBruiteForces(A);
    print(result, "stack Force");
    return 0;
}
vector<int> nearestGreaterInRight(vector<int> &A)
{
    int n = A.size(), i = n - 1;
    vector<int> result;
    stack<int> mystack;

    for (i = n - 1; i >= 0; i--)
    {
        int val = A[i];
        if (mystack.empty())
        {
            result.push_back(-1);
        }
    }
    reverse(result.begin(), result.end());

    return result;
}

vector<int> nearestGreaterInRightBruiteForces(vector<int> &A)
{
    int n = A.size(), i = 0, j = 0;
    vector<int> result = A;
    for (i = 0; i < n; i++)
    {
        int val = A[i];
        cout << val << " : ";
        for (j = i + 1; j < n; j++)
        {
            cout << A[j] << " ";
            if (A[j] > val)
            {
                result[i] = A[j];
                break;
            }
        }
        cout << endl;
    }
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
