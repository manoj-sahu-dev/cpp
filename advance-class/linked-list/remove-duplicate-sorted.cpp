#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief Given a sorted linked list, delete all duplicates such that each element appears only once.
 *
 * @param A
 * @return ListNode*
 */
ListNode *deleteDuplicates(ListNode *A);
/**
 * @brief insert node in linked list at position
 *
 * @param A
 * @param positions
 * @param value
 * @return ListNode*
 */
ListNode *insert(ListNode *A, int positions, int value);
/**
 * @brief print linked list
 *
 * @param A
 */
void print(ListNode *A);
int main(int argc, char **argv)
{
    system("clear");
    ListNode *head = NULL;

    head = insert(head, 1, 5);
    head = insert(head, 2, 6);
    head = insert(head, 3, 7);
    head = insert(head, 4, 8);
    head = insert(head, 5, 8);
    head = insert(head, 6, 9);
    head = insert(head, 7, 9);
    head = insert(head, 8, 10);
    print(head);
    head = deleteDuplicates(head);
    print(head);
    return 0;
}

ListNode *deleteDuplicates(ListNode *A)
{
    ListNode *current = A, *next = NULL;

    while (current->next != NULL)
    {
        next = current->next;
        while (current->val == next->val)
        {
            if (next->next == NULL)
            {
                current->next = NULL;
                return A;
            }
            next = next->next;
        }
        current->next = next;
        current = next;
    }

    return A;
}

ListNode *insert(ListNode *A, int position, int value)
{
    ListNode *temp = new ListNode(value);
    if (position == 1)
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