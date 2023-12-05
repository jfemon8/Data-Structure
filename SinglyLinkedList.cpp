#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
    cout << endl
         << v << " is inserted successfully at the Head." << endl;
}

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        insert_at_head(head, v);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << endl
         << v << " is inserted successfully at the Tail." << endl;
}

void insert_at_specific_position(Node *&head, int pos, int v)
{
    if (pos == 1)
    {
        insert_at_head(head, v);
        return;
    }
    Node *newNode = new Node(v);
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "\nInvalid position." << endl;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << endl
         << v << " is inserted at the " << pos << "th position successfully." << endl;
}

void delete_from_head(Node *&head)
{
    if (head == NULL)
    {
        cout << "\nLinked List is empty." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "\nHead is deleted successfully." << endl;
}

void delete_from_tail(Node *&head)
{
    if (head->next == NULL)
    {
        delete_from_head(head);
        return;
    }
    int c = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        c++;
    }
    Node *tmp = head;
    for (int i = 1; i < c - 1; i++)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
    delete temp;
    cout << "\nTail deleted successfully." << endl;
}

void delete_from_specific_position(Node *&head, int pos)
{
    if (pos == 1)
    {
        delete_from_head(head);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "\nInvalid position." << endl;
            return;
        }
    }
    if (temp->next == NULL)
    {
        cout << "\nInvalid position." << endl;
        return;
    }
    else if (temp->next->next == NULL)
    {
        delete_from_tail(head);
        return;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    cout << endl
         << pos << "th Node is deleted successfully." << endl;
}

void print(Node *head)
{
    cout << "\n*** The Linked List is: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "***" << endl;
}

int main()
{
    Node *head = NULL;
    while (true)
    {
        cout << "\nOption 1: Insert value at Head" << endl;
        cout << "Option 2: Insert value at Tail" << endl;
        cout << "Option 3: Insert at specific position" << endl;
        cout << "Option 4: Delete Head" << endl;
        cout << "Option 5: Delete from specific position" << endl;
        cout << "Option 6: Delete from Tail" << endl;
        cout << "Option 7: Print the Linked List" << endl;
        cout << "Option 8: Terminate" << endl;
        cout << "\nPlease insert an option: ";
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "\nPlease insert the value: ";
            int v;
            cin >> v;
            insert_at_head(head, v);
        }
        if (op == 2)
        {
            cout << "\nPlease insert the value: ";
            int v;
            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 3)
        {
            int pos, v;
            cout << "\nPlease enter the position: ";
            cin >> pos;
            cout << "Please insert the value: ";
            cin >> v;
            insert_at_specific_position(head, pos, v);
        }
        else if (op == 4)
        {
            delete_from_head(head);
        }
        else if (op == 5)
        {
            int pos;
            cout << "\nPlease enter the position: ";
            cin >> pos;
            delete_from_specific_position(head, pos);
        }
        else if (op == 6)
        {
            delete_from_tail(head);
        }
        else if (op == 7)
        {
            print(head);
        }
        else if (op == 8)
        {
            cout << "\nLinked List has been terminated. Thank you!" << endl;
            break;
        }
    }

    return 0;
}
