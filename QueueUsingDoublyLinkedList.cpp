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

class myQueue
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int s = 0;

public:
    void push(int val)
    {
        Node *newNode = new Node(val);
        s++;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void pop()
    {
        s--;
        Node *dltNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        delete dltNode;
    }
    int front()
    {
        return head->val;
    }
    int sz()
    {
        return s;
    }
    bool empty()
    {
        if (s == 0)
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    myQueue q;
    while (true)
    {
        int x;
        cout << endl
             << "Option 1: Push element into Queue" << endl
             << "Option 2: Pop element from Queue" << endl
             << "Option 3: View front" << endl
             << "Option 4: View size" << endl
             << "Option 5: Exit" << endl
             << endl
             << "Please enter an option: ";
        cin >> x;
        if (x == 1)
        {
            int v;
            cout << endl
                 << "Please enter a value: ";
            cin >> v;
            q.push(v);
            cout << endl
                 << "Value inserted to the Queue successfully." << endl;
        }
        else if (x == 2)
        {
            if (!q.empty())
            {
                q.pop();
                cout << endl
                     << "Popped element from Queue." << endl;
            }
            else
            {
                cout << endl
                     << "Queue is empty." << endl;
            }
        }
        else if (x == 3)
        {
            if (!q.empty())
            {
                cout << endl
                     << "The front value is " << q.front() << endl;
            }
            else
            {
                cout << endl
                     << "Queue is empty." << endl;
            }
        }
        else if (x == 4)
        {
            cout << endl
                 << "Size of the Queue is " << q.sz() << endl;
        }
        else if (x == 5)
        {
            cout << endl
                 << "Queue has been terminated, Thank you." << endl;
            break;
        }
        else
        {
            cout << endl
                 << "Invalid option." << endl;
        }
    }

    return 0;
}
