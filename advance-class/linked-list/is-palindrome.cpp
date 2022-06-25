#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int lPalin(ListNode *A);
ListNode *reverse(ListNode *A);
ListNode *getMiddle(ListNode *A);
void print(ListNode *A);

int main(int argc, char **argv)
{
    system("clear");
    ListNode *A = new ListNode(3);
    ListNode *A1 = new ListNode(3);
    ListNode *A2 = new ListNode(7);
    ListNode *A3 = new ListNode(3);
    ListNode *A4 = new ListNode(6);
    A->next = A1;
    // A1->next = A2;
    // A2->next = A3;
    // A3->next = A4;

    print(A);
    int pal = lPalin(A);
    cout << "it is palindrome: " << pal << endl;
    return 0;
}

int lPalin(ListNode *A)
{
    int isPalindrome = 1;
    if (A == NULL)
        return 1;

    ListNode *slow = A, *fast = A;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow = reverse(slow);
    fast = A;

    while (slow != NULL)
    {
        cout << slow->val << endl;
        if (slow->val != fast->val)
        {
            return 0;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return 1;
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
    return prev;
}

ListNode *getMiddle(ListNode *A)
{
    if (A == NULL)
        return NULL;

    ListNode *slow = A, *fast = A;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
