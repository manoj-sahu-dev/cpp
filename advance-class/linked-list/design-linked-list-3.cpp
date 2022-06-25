#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *solve(vector<vector<int>> &A);
ListNode *insert(ListNode *A, int positions, int value);
ListNode *delete_node(ListNode *A, int position);
/**
 * @brief print linked list
 *
 * @param A
 */
void print(ListNode *A);
int nodeCount = 0;
int main(int argc, char **argv)
{
    system("clear");
    ListNode *head = NULL;
    vector<vector<int>> A{{2, 1, 1}};
    head = solve(A);
    print(head);
    return 0;
}

ListNode *solve(vector<vector<int>> &A)
{
    int row = A.size();
    int col = A[0].size();

    ListNode *head = NULL;

    for (int i = 0; i < row; i++)
    {
        int operation = A[i][0];
        int value = A[i][1];
        int position = A[i][2];

        cout << "operation: " << operation << ", value: " << value << ", position: " << position << endl;
        switch (operation)
        {
        case 0:
            head = insert(head, 1, value);
            break;
        case 1:
            head = insert(head, nodeCount, value);
            break;
        case 2:
            head = insert(head, position, value);
            break;
        case 3:
            head = delete_node(head, nodeCount);
            break;
        }
    }
    return head;
}

/**
 * @brief delete a node at given position
 *
 * @param position
 */
ListNode *delete_node(ListNode *A, int position)
{
    cout << "delete_node: " << position << endl;
    if (A == NULL)
        return A;
    if (position > nodeCount)
        return A;
    if (position == 1)
    {
        A = A->next;
        nodeCount--;
        return A;
    }
    ListNode *node = A;
    int counter = 1;
    while (node != NULL)
    {
        if (position == (counter + 1))
        {
            cout << "removing at position " << position << endl;
            node->next = node->next->next;
            nodeCount--;
        }
        node = node->next;
        counter += 1;
    }
    return A;
}

ListNode *insert(ListNode *A, int position, int value)
{
    cout << "inserting at position : " << position << ", value : " << value << ", nodeCount: " << nodeCount << endl;

    ListNode *temp = new ListNode(value);
    if (position == 0)
    {
        if (A == NULL)
        {
            A = temp;
        }
        else
        {
            temp->next = A;
            A = temp;
        }
        nodeCount++;

        return A;
    }
    int i = 1;
    ListNode *node = A;
    while (node != NULL)
    {
        if (position == (i + 1))
        {
            cout << "inserting at position : " << i << ", value : " << node->val << endl;
            temp->next = node->next;
            node->next = temp;
            nodeCount++;
        }
        node = node->next;
        i += 1;
    }
    return A;
}

void print(ListNode *A)
{
    cout << "content of node : ";
    ListNode *node = A;
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}