#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *right;
    ListNode *down;
    ListNode(int x) : val(x), right(NULL), down(NULL) {}
};

/**
 * @brief Given a linked list where every node represents a linked list and contains two pointers of its type:
 * Pointer to next node in the main list (right pointer)
 * Pointer to a linked list where this node is head (down pointer). All linked lists are sorted.
 * You are asked to flatten the linked list into a single list. Use down pointer to link nodes of the flattened list. The flattened linked list should also be sorted.
 *
 * @param A
 * @return ListNode*
 */
ListNode *flatten(ListNode *A);
ListNode *get_middle(ListNode *A);
ListNode *merge(ListNode *A, ListNode *B);
void print(string statement = "");
int main(int argc, char **argv)
{
    system("clear");
    return 0;
}

ListNode *flatten(ListNode *root)
{
    if (root == NULL || root->down == NULL)
        return NULL;
    ListNode *middle = get_middle(root);
    ListNode *B = middle->right;

    middle->down = NULL;

    root = flatten(root);
    B = flatten(B);

    return merge(root, B);
}

ListNode *merge(ListNode *A, ListNode *B)
{
    ListNode *node = new ListNode(-1), *tail = node;

    while (A != NULL && B != NULL)
    {
        if (A->val < B->val)
        {
            tail->down = A;
            A = A->down;
        }
        else
        {
            tail->down = B;
            B = B->down;
        }
        tail = tail->down;
    }
    tail->down == A == NULL ? B : A;
    return node->down;
}

ListNode *get_middle(ListNode *A)
{
    if (A == NULL)
        return NULL;
    ListNode *slow = A, *fast = A;

    while (fast && fast->right)
    {
        slow = slow->right;
        fast = fast->right->right;
    }
    return slow;
}

void print(ListNode *A, string statement)
{
    if (statement != "")
        cout << statement;
    cout << " : content -> ";
    ListNode *node = A;
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->right;
    }
    cout << endl;
}