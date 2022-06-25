#include <iostream>

using namespace std;

class Node
{

public:
    int val;

    Node *next;
};

Node *head = NULL;

void insert_node(int position, int value)
{

    Node *a = head;

    int i = 1;

    if (position == 1)
    {

        if (head != NULL)
        {

            Node *n = new Node();

            n->val = value;

            n->next = head;

            head = n;

            return;
        }

        Node *n = new Node();

        n->val = value;

        head = n;

        return;
    }

    while (a != NULL)
    {

        if (position - 1 == i)
        {

            Node *n = new Node();

            n->val = value;

            n->next = a->next;

            a->next = n;

            return;
        }

        a = a->next;

        i++;
    }
}

void delete_node(int position)
{

    Node *a = head;

    int i = 1;

    if (position == 1)
    {

        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            head = NULL;
            return;
        }

        head = head->next;

        return;
    }

    while (a->next != NULL)
    {

        if (position - 1 == i)
        {

            a->next = a->next->next;

            return;
        }
    }
}
void print_ll()
{

    Node *a = head;
    while (a != NULL)
    {
        cout << a->val << " ";
        a = a->next;
    }
}

int main(int argc, char **argv)
{
    system("clear");
    insert_node(23, 1);
    print_ll();
    return 0;
}