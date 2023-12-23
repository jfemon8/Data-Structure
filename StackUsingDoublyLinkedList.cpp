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

class myStack
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

public:
    void push(int val)
    {
        Node *newNode = new Node(val);
        sz++;
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
        Node *dltNode = tail;
        sz--;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        delete dltNode;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if (sz == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    myStack st;
    while (true)
    {
        cout << endl
             << "Option 1: Push element into stack" << endl
             << "Option 2: Pop element from stack" << endl
             << "Option 3: View top element" << endl
             << "Option 4: View size of stack" << endl
             << "Option 5: Exit" << endl
             << endl
             << "Please enter an option: ";
        int n;
        cin >> n;
        if (n == 1)
        {
            int x;
            cout << endl
                 << "Please enter a value: ";
            cin >> x;
            st.push(x);
            cout << endl
                 << "Successfully pushed." << endl;
        }
        else if (n == 2)
        {
            if (!st.empty())
            {
                st.pop();
                cout << endl
                     << "Successfully popped." << endl;
            }
            else
            {
                cout << endl
                     << "Stack is empty." << endl;
            }
        }
        else if (n == 3)
        {
            if (!st.empty())
            {
                cout << endl
                     << "Top element is " << st.top() << endl;
            }
            else
            {
                cout << endl
                     << "Stack is empty." << endl;
            }
        }
        else if (n == 4)
        {
            cout << endl
                 << "Size of the is " << st.size() << endl;
        }
        else if (n == 5)
        {
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
