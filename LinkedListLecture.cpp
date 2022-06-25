#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> solve(vector<int> A, int B);

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }
};

int main()
{
    Node head(1);
    head.data = 100;
    head.next = NULL;
    cout << head.data << endl;
    cout << head.next << endl;
    return 0;
}

long solve(int A, vector<int> &B)
{
    int zero = 0;
    long result = 0;

    for (int i = 0; i < A; i++)
    {
        if (B[i] == 1)
        {
            result += (A - i);
            if (zero > 0)
            {
                result += (zero * (A - i));
                zero = 0;
            }
        }
        else
        {
            zero++;
        }
    }
    return result;
}

vector<int> solve(vector<int> A, int B)
{
    vector<int> arr;
    int prev = A[0];
    int count = 0;
    if (B == 0)
    {
        arr.push_back(0);
    }
    for (int i = 1; i < A.size(); i++)
    {
        if (prev != A[i])
        {
            count++;
            if (count >= (2 * B))
            {
                arr.push_back(i - B);
            }
            prev = A[i];
        }
        else
        {
            if (B == 0)
            {
                arr.push_back(i);
            }
            count = 0;
        }
    }
    return arr;
}