#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief Sort a linked list, A in O(n log n) time using constant space complexity.
 *
 * @param A
 * @return ListNode*
 */
ListNode *sortList(ListNode *A);

/**
 * @brief Merge two sorted linked lists, A and B, and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists and should also be sorted.
 *
 * @param A
 * @param B
 * @return ListNode*
 */
ListNode *mergeTwoLists(ListNode *A, ListNode *B);

ListNode *getMiddle(ListNode *A);

void print(ListNode *A, string from = "");

int main()
{
    system("clear");
    ListNode *A = new ListNode(3);
    ListNode *A2 = new ListNode(4);
    ListNode *A3 = new ListNode(2);
    ListNode *A4 = new ListNode(8);
    ListNode *A5 = new ListNode(5);

    A->next = A2;
    A2->next = A3;
    A3->next = A4;
    A4->next = A5;

    print(A, "A");
    A = sortList(A);
    print(A, "sorted A");
    return 0;
}

ListNode *sortList(ListNode *A)
{
    if (A == NULL || A->next == NULL)
        return A;

    ListNode *middle = getMiddle(A);
    ListNode *next = middle->next;
    middle->next = NULL;

    A = sortList(A);
    next = sortList(next);

    A = mergeTwoLists(A, next);

    return A;
}

ListNode *getMiddle(ListNode *A)
{
    if (A == NULL)
        return NULL;

    ListNode *slow = A, *fast = A;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *mergeTwoLists(ListNode *A, ListNode *B)
{
    ListNode *node = new ListNode(-1), *tail = node;

    while (A != NULL && B != NULL)
    {
        if (A->val < B->val)
        {
            tail->next = A;
            A = A->next;
        }
        else
        {
            tail->next = B;
            B = B->next;
        }
        tail = tail->next;
    }
    if (A == NULL)
    {
        tail->next = B;
    }
    if (B == NULL)
    {
        tail->next = A;
    }

    node = node->next;

    return node;
}

void print(ListNode *A, string from)
{
    ListNode *node = A;
    cout << from << "  list -> : ";
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
