#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}

void insert(vector<int> &array, int right_index, int value);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{3, 5, 7, 11, 13, 2, 9, 6};
    print(A);
    insert(A, 4, 2);
    print(A);
    return 0;
    sort(A.begin(), A.end());
}

void insert(vector<int> &array, int right_index, int value)
{
    array.push_back(value);
    int n = array.size();
    for (int i = n - 1; i >= (n - right_index - 1); i--)
    {

        cout << "A[" << i << "]: " << array[i] << endl;
        swap(array[i], array[i - 1]);
    }
}