#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << endl
             << "New Linked List has been created." << endl;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    cout << endl
         << "Value inseted at the head successfully." << endl;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        insert_at_head(head, tail, val);
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    cout << endl
         << "Value inserted at the tail successfully." << endl;
}

void insert_at_specific_position(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node(val);
    if (pos == 1)
    {
        insert_at_head(head, tail, val);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << endl
                 << "Invalid position." << endl;
            return;
        }
    }
    if (temp->next == NULL)
    {
        insert_at_tail(head, tail, val);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
    cout << endl
         << "Value inserted at " << pos << "th position successfully." << endl;
}

void delete_from_head(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << endl
             << "The Linked List is empty." << endl;
        return;
    }
    else if (head == tail)
    {
        Node *deleteNode = head;
        head = NULL;
        tail = NULL;
        delete deleteNode;
        cout << endl
             << "Last node of this Linked List has been deleted." << endl;
        return;
    }
    Node *deleteNode = head;
    head = head->next;
    head->prev = NULL;
    delete deleteNode;
    cout << endl
         << "Head has been deleted." << endl;
}

void delete_from_tail(Node *&head, Node *&tail)
{
    if (tail == NULL)
    {
        cout << endl
             << "The Linked List is empty." << endl;
        return;
    }
    else if (head == tail)
    {
        Node *deleteNode = tail;
        head = NULL;
        tail = NULL;
        delete deleteNode;
        cout << endl
             << "Last node of this Linked List has been deleted." << endl;
        return;
    }
    Node *deleteNode = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete deleteNode;
    cout << endl
         << "Tail has been deleted." << endl;
}

void delete_from_specific_position(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        delete_from_head(head, tail);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << endl
                 << "Invalid position." << endl;
            return;
        }
    }
    if (temp->next->next == NULL)
    {
        delete_from_tail(head, tail);
        return;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    deleteNode->next->prev = temp;
    delete deleteNode;
    cout << endl
         << pos << "th node has been deleted." << endl;
}

void print_in_ascending(Node *&head)
{
    if (head == NULL)
    {
        cout << endl
             << "The Linked List is empty." << endl;
        return;
    }
    Node *temp = head;
    cout << endl
         << "   ***   Linked List in Ascending Order: ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "  ***   " << endl;
}

void print_in_descending(Node *&tail)
{
    if (tail == NULL)
    {
        cout << endl
             << "The Linked List is empty." << endl;
        return;
    }
    Node *temp = tail;
    cout << endl
         << "   ***   Linked List in Descending Order: ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << "  ***   " << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        cout << "\nOption 1: Insert value at Head" << endl;
        cout << "Option 2: Insert value at Tail" << endl;
        cout << "Option 3: Insert value at specific position" << endl;
        cout << "Option 4: Delete from Head" << endl;
        cout << "Option 5: Delete from Tail" << endl;
        cout << "Option 6: Delete from specific position" << endl;
        cout << "Option 7: Print the Linked List in Ascending Order" << endl;
        cout << "Option 8: Print the Linked List in Descending Order" << endl;
        cout << "Option 9: Terminate" << endl;
        cout << "\nPlease insert an option: ";
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "\nPlease insert the value: ";
            int v;
            cin >> v;
            insert_at_head(head, tail, v);
        }
        if (op == 2)
        {
            cout << "\nPlease insert the value: ";
            int v;
            cin >> v;
            insert_at_tail(head, tail, v);
        }
        else if (op == 3)
        {
            int pos, v;
            cout << "\nPlease enter the position: ";
            cin >> pos;
            cout << "Please insert the value: ";
            cin >> v;
            insert_at_specific_position(head, tail, pos, v);
        }
        else if (op == 4)
        {
            delete_from_head(head, tail);
        }
        else if (op == 5)
        {
            delete_from_tail(head, tail);
        }
        else if (op == 6)
        {
            int pos;
            cout << "\nPlease enter the position: ";
            cin >> pos;
            delete_from_specific_position(head, tail, pos);
        }
        else if (op == 7)
        {
            print_in_ascending(head);
        }
        else if (op == 8)
        {
            print_in_descending(tail);
        }
        else if (op == 9)
        {
            cout << "\nLinked List has been terminated. Thank you!" << endl;
            break;
        }
    }

    return 0;
}
