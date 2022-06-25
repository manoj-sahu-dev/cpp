#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * @brief Given a singly linked list A
 * A: A0 → A1 → … → An-1 → An
 * reorder it to:
 * A0 → An → A1 → An-1 → A2 → An-2 → …
 * You must do this in-place without altering the nodes' values.
 *
 * @param A
 * @return ListNode*
 */
ListNode *reorderList(ListNode *A);
ListNode *reverseList(ListNode *A);
void print(ListNode *A, string from = "");
int main()
{
    system("clear");
    ListNode *A = new ListNode(1);
    ListNode *A2 = new ListNode(2);
    ListNode *A3 = new ListNode(3);
    ListNode *A4 = new ListNode(4);
    ListNode *A5 = new ListNode(5);
    ListNode *A6 = new ListNode(6);

    A->next = A2;
    A2->next = A3;
    A3->next = A4;
    A4->next = A5;
    // A5->next = A6;
    print(A, "A");
    A = reorderList(A);
    print(A, "A");
    return 0;
}

ListNode *reorderList(ListNode *A)
{
    ListNode *slow = A, *fast = A, *prev = NULL, *firstHalf = A;
    int count = 0;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        count += 1;
    }
    cout << "before middle: " << prev->val << ", middle: " << slow->val << ", count = " << count << endl;
    print(slow, "slow");
    print(A, "A");
    ListNode *secondHalf = reverseList(slow);
    print(secondHalf, "secondHalf");
    print(A, "A");
    firstHalf = A;
    print(firstHalf, "firstHalf");
    print(A, "A");
    while (firstHalf != NULL && secondHalf != NULL)
    {
        ListNode *temp = firstHalf->next;
        firstHalf->next = secondHalf;
        firstHalf = temp;

        temp = secondHalf->next;
        secondHalf->next = firstHalf;
        secondHalf = temp;
    }
    if (firstHalf != NULL)
    {
        firstHalf->next = NULL;
    }
    print(firstHalf, "firstHalf");
    return A;
}

ListNode *reverseList(ListNode *A)
{
    if (A == NULL)
        return NULL;
    ListNode *prev = NULL, *current = A;
    while (current != NULL)
    {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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