#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    Node next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

Node head = NULL;
static int length = 0;

int solve(vector<int> &A)
{
    int n = A.size();
    if (n > 1)
    {
        sort(A.begin(), A.end());
        int max = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] == max)
                continue;

            return A[i] % max;
        }
    }

    return 0;
}

void insert_node(int position, int value)
{
    // @params position, integer
    // @params value, integer
    Node newNode = new Node(value);
}

void delete_node(int position)
{
    // @params position, integer
}

void print_ll()
{
    // Output each element followed by a space
}

int main()
{
    system("clear");

    int cases, inputCount = 0;
    cin >> cases;
    while (cases > 0)
    {
        char op;
        int index, value;

        cin >> op;
        switch (op)
        {
        case 'i':
            cin >> index >> value;
            insert_node(index, value);
            break;
        case 'd':
            cin >> index;
            delete_node(index);
            break;
        case 'p':
            print_ll();
            break;
        }
        cases--;
    }
    return 0;
}