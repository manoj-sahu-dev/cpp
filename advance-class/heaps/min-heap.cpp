#include <iostream>
#include <vector>

using namespace std;

class min_heap
{
private:
    void heapify(vector<int> &arr, int n, int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[smallest] > arr[left])
        {
            smallest = left;
        }
        else if (right < n && arr[smallest] > arr[right])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest);
        }
    }

public:
    void print(vector<int> &arr)
    {
        cout << "size of vector: " << arr.size() << endl;
        for (auto x : arr)
        {
            cout << x << "  ";
        }
        cout << endl;
    }
    vector<int> buildMinHeap(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
        return arr;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");
    min_heap minHeap;
    // vector<int> A{9, 3, 2, 6, 7};
    vector<int> A{8, 9, 0};
    minHeap.print(A);
    vector<int> result = minHeap.buildMinHeap(A);
    minHeap.print(result);
    return 0;
}
