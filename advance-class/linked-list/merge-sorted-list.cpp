#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief Merge two sorted linked lists, A and B, and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists and should also be sorted.
 *
 * @param A
 * @param B
 * @return ListNode*
 */
ListNode *mergeTwoLists(ListNode *A, ListNode *B);

void print(ListNode *A, string from = "");

int main()
{
    system("clear");
    ListNode *A = new ListNode(3);
    ListNode *A2 = new ListNode(8);
    ListNode *A3 = new ListNode(10);
    ListNode *A4 = new ListNode(14);
    ListNode *A5 = new ListNode(20);

    ListNode *B = new ListNode(2);
    ListNode *B2 = new ListNode(6);
    ListNode *B3 = new ListNode(11);
    ListNode *B4 = new ListNode(12);

    A->next = A2;
    A2->next = A3;
    A3->next = A4;
    A4->next = A5;

    B->next = B2;
    B2->next = B3;
    B3->next = B4;
    print(A, "A");
    print(B, "B");
    ListNode *merged = mergeTwoLists(A, B);
    print(merged, "merged");
    return 0;
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
