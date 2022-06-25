#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
int listCount(ListNode *current, ListNode *next);
/**
 * @brief Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list.
 * A palindrome list is a list that reads the same backward and forward.
 * Expected memory complexity : O(1)
 *
 * @param A
 * @return int
 */
int solve(ListNode *A);
void print(ListNode *A);
int main(int argc, char **argv)
{
    system("clear");
    ListNode *A = new ListNode(2);
    ListNode *A1 = new ListNode(1);
    ListNode *A2 = new ListNode(2);
    ListNode *A3 = new ListNode(1);
    ListNode *A4 = new ListNode(2);
    ListNode *A5 = new ListNode(2);
    ListNode *A6 = new ListNode(1);
    ListNode *A7 = new ListNode(3);
    ListNode *A8 = new ListNode(2);
    ListNode *A9 = new ListNode(2);

    A->next = A1;
    A1->next = A2;
    A2->next = A3;
    A3->next = A4;
    A4->next = A5;
    A5->next = A6;
    A6->next = A7;
    A7->next = A8;
    A8->next = A9;

    print(A);
    int result = solve(A);
    cout << "longest palindrome is: " << result << endl;
    return 0;
}
int listCount(ListNode *current, ListNode *next)
{
    int count = 0;

    while (current != NULL && next != NULL)
    {
        if (current->val != next->val)
        {
            break;
        }
        count += 2;
        current = current->next;
        next = next->next;
    }
    return count;
}

int solve(ListNode *A)
{
    int ans = 0;

    ListNode *current = A, *prev = NULL;
    while (current != NULL)
    {
        // reverse linked list till current node
        ListNode *next = current->next;
        current->next = prev;

        ans = max(ans, listCount(current, next));

        ans = max(ans, listCount(prev, next) + 1);

        prev = current;
        current = next;
    }
    return ans;
}

void print(ListNode *A)
{
    ListNode *node = A;
    cout << "content: ";
    while (node != NULL)
    {
        cout << node->val << "  ";
        node = node->next;
    }
    cout << endl;
}