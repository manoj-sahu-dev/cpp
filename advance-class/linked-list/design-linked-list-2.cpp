#include <iostream>

using namespace std;

/**
 * @brief singly linked list
 * Design and implement a Linked List data structure.
 * A node in a linked list should have the following attributes - an integer value and a pointer to the next node. It should support the following operations:
 *
 * insert_node(position, value) - To insert the input value at the given position in the linked list.
 * delete_node(position) - Delete the value at the given position from the linked list.
 * print_ll() - Print the entire linked list, such that each element is followed by a single space.
 * Note:

 * If an input position does not satisfy the constraint, no action is required.
 * Each print query has to be executed in a new line.
 */
class Node
{
private:
    int val;

public:
    /**
     * @brief get the value of this node
     * @return int
     */
    int get() { return val; }

    Node *next = NULL;

    /**
     * @brief Construct a new Node object
     *
     * @param value
     */
    Node(int value)
    {
        val = value;
    }
};

Node *head = NULL;
int nodeCount = 0;

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
    print_ll();
    insert_node(1, 22);
    insert_node(1, 21);
    print_ll();
    delete_node(1);
    print_ll();
    delete_node(2);
    print_ll();
    return 0;
}

/**
 * @brief inser a node at given position
 *
 * @param position
 * @param value
 */
void insert_node(int position, int value)
{
    cout << "insert_node: " << position << " -> " << value << endl;
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
        nodeCount += 1;
        return;
    }
    Node *pointer = head;
    int counter = 1;
    while (pointer != NULL)
    {
        if (position == (counter + 1))
        {
            temp->next = pointer->next;
            pointer->next = temp;
            nodeCount += 1;
        }
        pointer = pointer->next;
        counter += 1;
    }
}

/**
 * @brief delete a node at given position
 *
 * @param position
 */
void delete_node(int position)
{
    cout << "delete_node: " << position << endl;
    if (head == NULL)
        return;
    if (position > nodeCount)
        return;
    if (position == 1)
    {
        head = head->next;
        nodeCount -= 1;
        return;
    }
    Node *node = head;
    int counter = 1;
    while (node != NULL)
    {
        if (position == (counter + 1))
        {
            cout << "removing at position " << position << endl;
            node->next = node->next->next;
            nodeCount -= 1;
        }
        node = node->next;
        counter += 1;
    }
}

/**
 * @brief print the nodes
 */
void print_ll()
{
    cout << "total nodes: " << nodeCount << " -> ";
    if (head == NULL)
        return;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            cout << temp->get() << " ";
        }
        else
        {
            cout << temp->get();
        }
        temp = temp->next;
    }

    cout << endl;
}