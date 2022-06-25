#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * @brief Given a linked list A and a value B, partition it such that all nodes less than B come before nodes greater than or equal to B.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * @param A
 * @param B
 * @return ListNode*
 */
ListNode *partition(ListNode *A, int B);
void print(ListNode *A);
int main(int argc, char **argv)
{
    system("clear");
    ListNode *A = new ListNode(1);
    ListNode *A1 = new ListNode(4);
    ListNode *A2 = new ListNode(3);
    ListNode *A3 = new ListNode(2);
    ListNode *A4 = new ListNode(5);
    ListNode *A5 = new ListNode(2);
    // A->next = A1;
    // A1->next = A2;
    // A2->next = A3;
    // A3->next = A4;
    // A4->next = A5;

    print(A);
    ListNode *B = partition(A, 1);
    print(B);
    return 0;
}

ListNode *partition(ListNode *A, int B)
{
    ListNode *first = new ListNode(-1), *second = new ListNode(-1);
    ListNode *temp1 = first, *temp2 = second;
    while (A != NULL)
    {
        if (A->val < B)
        {
            temp1->next = A;
            A = A->next;
            temp1 = temp1->next;
        }
        else
        {
            temp2->next = A;
            A = A->next;
            temp2 = temp2->next;
        }
    }
    temp1->next = NULL;
    temp2->next = NULL;
    first = first->next;
    second = second->next;
    if (first == NULL)
        return second;
    temp1->next = second;
    return first;
}

void print(ListNode *A)
{
    cout << "node: ";
    ListNode *node = A;
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}