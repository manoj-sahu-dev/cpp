#include <iostream>

using namespace std;

void print(int arr[], int n)
{
    cout << "size of arr: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    else if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{

    for (int i = n - 1; i > 0; i--)
    {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void build_heap(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main(int argc, char const *argv[])
{
    system("clear");

    int arr[] = {9, 3, 2, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    heap_sort(arr, n);
    print(arr, n);
    return 0;
}
