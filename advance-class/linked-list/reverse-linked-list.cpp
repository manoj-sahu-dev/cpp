#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next = NULL;
    Node(int value) : value(value){};
};
Node *head = NULL;
void insert(int position, int value);
/**
 * @brief You are given a singly linked list having head node A. You have to reverse the linked list and return the head node of that reversed list.
 * NOTE: You have to do it in-place and in one-pass.
 * @param A
 * @return Node*
 */
Node *reverseList(Node *A);
void print(string statement = "");
int main(int argc, char **argv)
{
    system("clear");
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 5);
    insert(6, 6);
    print("after inserting");
    reverseList(head);
    print("after reverse");
    return 0;
}

void insert(int position, int value)
{
    Node *temp = new Node(value);
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
    int counter = 1;
    Node *node = head;
    while (node != NULL)
    {
        if (position == (counter + 1))
        {
            cout << "inserting at position: " << position << ", value: " << value << endl;
            temp->next = node->next;
            node->next = temp;
        }
        node = node->next;
        counter++;
    }
}
Node *reverseList(Node *A)
{
    if (A == NULL)
        return NULL;
    Node *prev = NULL, *current = A;
    while (current != NULL)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return A;
}
void print(string statement)
{
    if (statement != "")
        cout << statement;
    cout << " : content -> ";
    Node *node = head;
    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}