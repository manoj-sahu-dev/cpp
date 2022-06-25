#include <iostream>
#include <vector>

using namespace std;

int max_sub_array_size_k(vector<int> &A, int k = 1);
vector<int> get_prefix_sum(vector<int> &A);
void print(const vector<int> &A, string vn);

int main()
{
    system("clear");
    vector<int> A{2, 5, 1, 8, 2, 9, 1};
    print(A, "A");
    int result = max_sub_array_size_k(A, 3);
    cout << "result = " << result << endl;
    return 0;
}

int max_sub_array_size_k(vector<int> &A, int k)
{
    int i = 0, j = 0, n = A.size(), sum = 0, msum = 0;

    while (j < n) // standard way to traverse sliding widnow with fix size
    {
        sum += A[j];
        if ((j - i + 1) == k)
        {
            msum = max(msum, sum);
            sum -= A[i];
            i += 1;
        }
        j += 1;
    }
    return msum;
}

vector<int> get_prefix_sum(vector<int> &A)
{
    int n = A.size(), sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        A[i] = sum;
    }
    return A;
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
