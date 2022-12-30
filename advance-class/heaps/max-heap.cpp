#include <iostream>
#include <vector>

using namespace std;

class max_heap
{
private:
    int size;
    vector<int> values;

public:
    max_heap()
    {
        values.push_back(-1);
        size = 0;
    }

    void insert(int value)
    {
        values.push_back(value);
        size++;

        int index = size;

        while (index > 1)
        {
            int parent = index / 2;
            // cout << "index: " << index << " parent: " << parent << ", parent value: " << values[parent] << ", index value: " << values[index] << endl;
            if (values[parent] < values[index])
            {
                swap(values[parent], values[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void remove()
    {
        if (size == 0)
        {
            return;
        }
        cout << "removing " << values[1] << ", size: " << size << endl;
        values[1] = values[size]; // put last value into first position
        size--;

        int index = 1;

        // take root node to correct position
        while (index < size)
        {
            int left_index = index * 2;
            int right_index = index * 2 + 1;

            int res = values[index], temp = index;
            if (left_index <= size && right_index <= size)
            {
                if (values[left_index] > res)
                {
                    res = values[left_index];
                    temp = left_index;
                }
                if (values[right_index] > res)
                {
                    res = values[right_index];
                    temp = right_index;
                }
            }
            if (res > values[index])
            {
                swap(values[index], values[temp]);
                index = temp;
            }
            else
            {
                break;
            }
        }
        values.pop_back(); // remove last value
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << values[i] << "  ";
        }
        cout << endl;
    }
};

int main(int argc, const char **argv)
{
    system("clear");
    max_heap m_heap;
    m_heap.insert(70);
    m_heap.print();
    m_heap.insert(24);
    m_heap.print();
    m_heap.insert(28);
    m_heap.print();
    m_heap.remove();
    m_heap.print();
    m_heap.insert(26);
    m_heap.print();
    m_heap.insert(74);
    m_heap.print();
    m_heap.insert(36);
    m_heap.print();
    m_heap.insert(78);
    m_heap.print();
    m_heap.remove();
    m_heap.print();
    return 0;
}