#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > subsets(vector<int> &A);

int main()
{
    system("clear");
    vector<int> A{1, 2, 3};

    for (int i = 1; i <= 10; i++)
    {
        cout << i << " : " << (i & 2) << endl;
    }
    return 0;
    vector<vector<int> > sub = subsets(A);

    // for (int i = 0; i < A.size(); i++)
    // {
    //     for (int j = i; j < A.size(); j++)
    //     {
    //         for (int k = i; k <= j; k++)
    //         {
    //             cout << A[k] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    int size = sub.size();
    for (int i = 0; i < size; i++)
    {
        int innerSize = sub[i].size();
        for (int j = 0; j < innerSize; j++)
        {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<vector<int> > subsets(vector<int> &A)
{
    set<vector<int> > mset;
    int n = (1 << A.size());
    for (int i = 1; i < n; i++)
    {
        int index = 0, num = i;
        vector<int> temp;
        while (num != 0)
        {
            cout << num << endl;
            if (num & 1)
            {
                temp.push_back(A[index]);
                cout << "adding: " << num << " : " << A[index] << endl;
            }
            num >>= 1;
            index += 1;
        }
        // for (int i = 0; i < temp.size(); i++)
        // {
        //     cout << temp[i] << " ";
        // }
        mset.insert(temp);
        cout << endl
             << "#############" << endl;
    }

    vector<vector<int> > result;
    result.push_back({});

    for (auto n : mset)
    {
        result.push_back(n);
    }
    return result;
}
