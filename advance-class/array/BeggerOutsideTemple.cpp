#include <iostream>
#include <vector>

using namespace std;

vector<int> findBeggerMoney(int A, vector<vector<int> > &B);
void print(const vector<int> &A, string vn = "");
void print(const vector<vector<int> > &A, string vn = "");

int main()
{
    system("clear");
    int A = 5;
    vector<vector<int> > B{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    print(B, "B");
    vector<int> result = findBeggerMoney(A, B);
    print(result, "result");
    return 0;
}

vector<int> findBeggerMoney(int A, vector<vector<int> > &B)
{
    vector<int> vec, ps;

    vec.assign(A, 0);
    ps.assign(A, 0);

    int i = 0, n = B.size();

    print(vec, "vec");

    for (i = 0; i < n; i++)
    {
        int start_range = B[i][0] - 1; // indexes starts from 0
        int end_range = B[i][1];
        int amount = B[i][2];

        vec[start_range] += amount;

        if (end_range < A)
        {
            vec[end_range] += -amount;
        }
    }

    ps[0] = vec[0];
    for (int i = 1; i < A; i++)
    {
        ps[i] = ps[i - 1] + vec[i];
    }
    print(vec, "vec");

    return ps;
}

void print(const vector<int> &A, string vn)
{
    if (vn != "")
        cout << "vector " << vn << " values: " << endl;
    for (auto a : A)
    {
        cout << a << " ";
    }
    cout << endl;
}
void print(const vector<vector<int> > &A, string vn)
{
    cout << "vector " << vn << " values: " << endl;
    for (vector<int> a : A)
    {
        print(a, "");
    }
    cout << endl;
}
