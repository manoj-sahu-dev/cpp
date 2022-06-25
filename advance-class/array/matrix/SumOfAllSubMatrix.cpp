#include <iostream>
#include <vector>

using namespace std;
void print(const vector<int> &A, string vn = "");
void print(const vector<vector<int> > &A, string vn = "");
int findSumOfAllSubMatrices(vector<vector<int> > &A);
int findSumOfAllSubMatricesBF(vector<vector<int> > &A);
int main()
{
    system("clear");
    vector<vector<int> > A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(A, "Matrix A");
    int result = findSumOfAllSubMatricesBF(A);
    cout << "result bruite force: " << result << endl;
    result = findSumOfAllSubMatrices(A);
    cout << "result: " << result << endl;
    return 0;
}

int findSumOfAllSubMatrices(vector<vector<int> > &A)
{
    int rows = A.size(), columns = A[0].size(), sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += A[i][j] * (i + 1) * (j + 1) * (rows - i) * (columns - j);
        }
    }
    return sum;
}

int findSumOfAllSubMatricesBF(vector<vector<int> > &A)
{
    int rows = A.size(), columns = A[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            for (int k = i; k < columns; k++)
            {
                for (int l = j; l < rows; l++)
                {
                    cout << A[k][l] << endl;
                }
            }
        }
    }
    return 0;
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