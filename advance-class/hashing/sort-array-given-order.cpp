#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print(vector<int> &A)
{
    cout << "content of vector: " << endl;
    for (auto x : A)
        cout << x << " ";
    cout << endl;
}

/**
 * @brief Given two arrays of integers A and B, Sort A in such a way that the relative order among the elements will be the same as those are in B.
 * For the elements not present in B, append them at last in sorted order.
 *
 * Return the array A after sorting from the above method.
 *
 * NOTE: Elements of B are unique.
 *
 * @param A first vector
 * @param B second vector
 * @return vector<int> sorted vector of integers
 */
vector<int> sortArrayInGivenOrder(vector<int> &A, vector<int> &B);

int main(int argc, char **argv)
{
    system("clear");

    vector<int> A{5, 17, 100, 11};
    vector<int> B{1, 100};
    print(A);
    print(B);
    vector<int> result = sortArrayInGivenOrder(A, B);
    print(result);

    return 0;
}
vector<int> sortArrayInGivenOrder(vector<int> &A, vector<int> &B)
{

    // brute force
    /*
    vector<int> ans;
    sort(A.begin(), A.end());
    int m = A.size(), n = B.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (B[i] == A[j])
            {
                ans.push_back(A[j]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        bool exists = false;
        for (int j = 0; j < ans.size(); j++)
        {
            cout << A[j] << " : " << A[i] << " : " << exists << endl;
            if (ans[j] == A[i])
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            cout << "not exist: " << A[i] << endl;
            ans.push_back(A[i]);
        }
    }*/
    map<int, int> countMap;
    for (auto num : A)
    {
        countMap[num] += 1;
    }

    int j = 0;

    for (auto num : B)
    {
        if (countMap[num])
        {
            for (int i = 0; i < countMap[num]; i++)
            {
                A[j] = num;
                j += 1;
            }
            countMap[num] = 0;
        }
    }

    for (auto num : countMap)
    {
        for (int i = 0; i < num.second; i++)
        {
            A[j] = num.first;
            j += 1;
        }
    }

    return A;
}