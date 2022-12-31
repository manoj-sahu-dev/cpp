#include <iostream>
#include <queue>

using namespace std;

class MaxHeap
{
private:
    void print(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

public:
    int kthSmallest(int arr[], int n, int k)
    {
        priority_queue<int> pq;
        cout << "n = " << n << ", k = " << k << endl;
        print(arr, n);
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        for (int i = k; i < n; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    MaxHeap heap;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int r = 0;
    int result = heap.kthSmallest(arr, n, k);
    cout << k << "th smallest element: " << result << endl;
    return 0;
}
