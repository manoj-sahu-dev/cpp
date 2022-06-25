#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    ListNode *next = NULL;
    ListNode(int val) : value(val){};
};
ListNode *head = NULL;

void insert(int positions, int value);
void print();
/**
 * @brief Given a singly linked list A and an integer B, reverse the nodes of the list B at a time and return the modified linked list.
 * @param A
 * @param B
 * @return ListNode*
 */
ListNode *reverseList(ListNode *A, int B);

int main(int argc, char **argv)
{
    system("clear");
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 5);
    insert(6, 6);
    print();
    head = reverseList(head, 2);
    print();
    return 0;
}

ListNode *reverseList(ListNode *A, int B)
{
    if (A == NULL)
        return NULL;

    ListNode *prev = NULL, *current = A, *next = NULL;
    int counter = 0;
    while (current != NULL && B > counter)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        counter++;
    }
    if (next != NULL)
    {
        A->next = reverseList(current, B);
    }
    return prev;
}

void insert(int positions, int value)
{
    ListNode *temp = new ListNode(value);
    if (positions == 1)
    {
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        return;
    }
    int counter = 1;
    ListNode *node = head;
    while (node != NULL)
    {
        if (positions == (counter + 1))
        {
            temp->next = node->next;
            node->next = temp;
        }
        node = node->next;
        counter++;
    }
}

void print()
{
    ListNode *node = head;
    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}