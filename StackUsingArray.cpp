#include <bits/stdc++.h>
using namespace std;

class myStack
{
private:
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        if (v.size() == 0)
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
