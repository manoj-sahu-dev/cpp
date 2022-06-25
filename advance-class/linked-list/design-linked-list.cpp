#include <iostream>

using namespace std;

/**
 * @brief node instance
 *
 */
class Node
{
public:
    int value;
    Node *next = NULL;
    Node(int value)
    {
        this->value = value;
    }
};

Node *head = NULL;

int length = 0;
void insert_node(int position, int value);
void delete_node(int position);
void print_ll();

int main(int argc, char **argv)
{
    system("clear");
    insert_node(1, 23);
    insert_node(2, 24);
    insert_node(3, 25);
    insert_node(4, 26);
    insert_node(1, 22);
    print_ll();
    delete_node(1);
    print_ll();
    delete_node(2);
    print_ll();
    return 0;
}

/**
 * @brief insert node at given position
 *
 * @param position
 * @param value
 */
void insert_node(int position, int value)
{
    if (position > length + 1 || position < 0)
        return;
    // cout << "position: " << position << " value: " << value << ", length: " << length << endl;
    Node *temp = new Node(value);
    int i = 1;
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
        length += 1;
        return;
    }
    Node *a = head;
    while (a != NULL)
    {
        if (position == (i + 1))
        {
            temp->next = a->next;
            a->next = temp;
            length += 1;
        }
        a = a->next;
        i++;
    }
}

/**
 * @brief delete node from given index
 *
 * @param position
 */
void delete_node(int position)
{
    if (position == 1)
    {
        if (head == NULL)
            return;
        head = head->next;
        length -= 1;
        return;
    }
    int i = 1;
    Node *temp = head;
    cout << "temp->value " << temp->value << endl;
    while (temp->next != NULL)
    {
        cout << ">> temp->next " << temp->next->value << ", position " << position << ", value " << temp->next->value << endl;
        if (position == i)
        {
            temp->next = temp->next->next;
            length -= 1;
            return;
        }
        i += 1;
    }
}

void print_ll()
{
    cout << "print: length: " << length << endl;
    Node *node = head;
    while (node->next != NULL)
    {
        cout << node->next->value << " ";
        node = node->next;
    }
    if (node != NULL)
    {
        cout << node->value;
    }
    // Output each element followed by a space
}