#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Places
{
private:
    void print(priority_queue<int, vector<int>, greater<int>> gq)
    {
        while (!gq.empty())
        {
            cout << gq.top() << "  ";
            gq.pop();
        }

        cout << endl;
    }

public:
    /**
     * @brief N people having different priorities are standing in a queue.
     * The queue follows the property that each person is standing at most B places away from its position in the sorted queue.
     * Your task is to sort the queue in the increasing order of priorities.
     *
     * NOTE:
     * No two persons can have the same priority.
     * Use the property of the queue to sort the queue with complexity O(NlogB).
     *
     * @param A vector
     * @param B size
     * @return vector<int>
     */
    vector<int> solve(vector<int> &A, int B)
    {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> pq;
        int size = B + 1;
        for (int i = 0; i < size; i++)
        {
            pq.push(A[i]);
        }
        print(pq);
        int n = A.size();
        for (int i = size; i < n; i++)
        {
            result.push_back(pq.top());
            pq.pop();
            pq.push(A[i]);
        }
        while (!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }

    void print(vector<int> &A)
    {
        cout << "size of A: " << A.size() << endl;
        for (int x : A)
            cout << x << "  ";
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    vector<int> A{6, 5, 3, 2, 8, 10, 9};

    int B = 3;
    Places places;
    places.print(A);
    vector<int> result = places.solve(A, B);
    places.print(result);
    return 0;
}
