#include <iostream>

using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;
    ListNode(int x) : value(x), next(NULL) {}
};

ListNode *head = NULL;

void insert(int position, int value)
{
    ListNode *temp = new ListNode(value);
    if (position == 1)
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
    int count = 1;
    ListNode *node = head;
    while (node != NULL)
    {
        if (position == (count + 1))
        {
            cout << "inserting at position " << position << endl;
            temp->next = node->next;
            node->next = temp;
        }
        node = node->next;
        count += 1;
    }
}
/**
 * @brief Given a singly linked list, delete middle of the linked list.
 *
 * For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5
 * If there are even nodes, then there would be two middle nodes, we need to delete the second middle element.
 * For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
 * Return the head of the linked list after removing the middle node.
 * If the input linked list has 1 node, then this node should be deleted and a null node should be returned.
 */
void delete_middle_node()
{
    if (head == NULL || head->next == NULL)
        return;

    ListNode *fast = head, *slow = head, *beforeMiddle = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        beforeMiddle = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "before middle: " << beforeMiddle->value << ", middle: " << slow->value << endl;
    beforeMiddle->next = slow->next;

    ListNode *prev = NULL, *slow = A, *fast = A;

    /*if (A == NULL || A->next == NULL)
        return NULL;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = A;
            while (slow != fast)
            {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            prev->next = NULL;
        }
    }*/
    return A;
}

void print()
{
    if (head == NULL)
        return;
    ListNode *node = head;
    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}
int main(int argc, char **argv)
{
    system("clear");

    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 5);
    print();
    delete_middle_node();
    print();
    return 0;
}
