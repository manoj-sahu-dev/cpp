#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Try solving it using constant additional space.
 *              ______
 *               |     |
 *               \/    |
 *      1 -> 2 -> 3 -> 4
 *
 * @param A
 * @return ListNode*
 */
ListNode *detectCycle(ListNode *A);

int main(int argc, char **argv)
{
    system("clear");
    ListNode *A = new ListNode(1);
    ListNode *detectCycle(A);
    return 0;
}

ListNode *detectCycle(ListNode *A)
{
    ListNode *slow = A, *fast = A;
    bool cycle = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cycle = true;
            break;
        }
    }
    if (!cycle)
        return NULL;

    ListNode *start = A;

    while (start != slow)
    {
        start = start->next;
        slow = slow->next;
    }
    return start;
}