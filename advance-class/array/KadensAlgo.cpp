#include <iostream>
#include <vector>

using namespace std;

int kadensAlgo(vector<int> &A);
void print(const vector<int> &A, string vn);

int main()
{
    system("clear");
    vector<int> A{-8, -3, -6, -2, -5, -4};
    print(A, "A");
    int result = kadensAlgo(A);
    cout << "result = " << result << endl;
    return 0;
}

int kadensAlgo(vector<int> &A)
{
    int i = 0, n = A.size(), cs = 0, ms = 0, si = 0, ee = 0;

    for (int i = 0; i < n; i++)
    {
        cs += A[i];
        if (cs < 0)
        {
            cs = 0;
            si = i + 1;
        }
        else
        {
            int temp = ms;
            ms = max(ms, cs);
            if (ms > temp)
                ee = i;
        }
    }
    cout << si << " : " << ee << endl;

    for (int i = si; i < ee; i++)
    {
        cout << A[i] << "  ";
    }
    return ms;
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
