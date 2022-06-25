#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode *A)
{

    cout << "\n--------\ncontent -> ";
    ListNode *node = A;
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n--------\n\n";
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
    ListNode *node = A;
    int count = 1;
    while (node != NULL)
    {
        if (position == (count + 1))
        {
            // cout << "inserting node at position " << position << ", value: " << value << endl;
            temp->next = node->next;
            node->next = temp;
        }
        node = node->next;
        count += 1;
    }
    return A;
}
/**
 * @brief reverse a linked list
 *
 * @param A
 * @return ListNode*
 */
ListNode *reverse(ListNode *A);

/**
 * @brief Reverse a linked list A from position B to C.
 *
 * NOTE: Do it in-place and in one-pass.
 *
 * @param A
 * @param position
 * @param value
 * @return ListNode*
 */
ListNode *reverseBetween(ListNode *A, int B, int C);
ListNode *removeNthFromEnd(ListNode *A, int B);

int main(int argc, char **argv)
{
    system("clear");

    ListNode *head = NULL;

    head = insert(head, 1, 1);
    head = insert(head, 2, 4);
    head = insert(head, 3, 3);
    head = insert(head, 4, 5);
    head = insert(head, 5, 2);
    head = insert(head, 6, 6);
    head = insert(head, 7, 8);
    print(head);
    head = reverseBetween(head, 2, 6);
    print(head);
    head = removeNthFromEnd(head, 3);
    print(head);
    return 0;
}
ListNode *removeNthFromEnd(ListNode *A, int B)
{
    ListNode *first = A, *second = A;
    int size = 0;
    while (first != NULL)
    {
        first = first->next;
        size++;
    }
    cout << "size of linked list: " << size << endl;
    if (B >= size)
    {
        A = A->next;
    }
    else
    {
        for (int i = 0; i < size - B - 1; i++)
        {
            second = second->next;
        }
        second->next = second->next->next;
    }
    return A;
}

ListNode *reverse(ListNode *A)
{
    if (A == NULL)
        return NULL;

    ListNode *current = A, *prev = NULL;
    while (current != NULL)
    {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return A;
}
ListNode *reverseBetween(ListNode *A, int B, int C)
{
    if (A == NULL)
        return NULL;

    ListNode *current = A;
    ListNode *from = NULL, *to = NULL, *first = NULL, *last = NULL;
    int counter = 1;
    while (current != NULL && counter <= C)
    {
        // cout << "counter = " << counter << endl;
        if (counter < B)
        {
            first = current;
            cout << "first = " << first->val << endl;
        }
        if (counter == B)
        {
            from = current;
            cout << "from = " << from->val << endl;
        }
        if (counter == C)
        {
            to = current;
            last = current->next;
            cout << "to = " << to->val << endl;
            cout << "last = " << last->val << endl;
            break;
        }
        current = current->next;

        counter += 1;
    }

    to->next = NULL;
    from = reverse(from);
    if (first != NULL)
    {
        first->next = to;
    }
    else
    {
        A = to;
    }
    from->next = last;
    return A;
}