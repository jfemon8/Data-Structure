#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool end;
    Node *next[26];
    Node()
    {
        end = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

Node *root = new Node();

void insert(string s, int n)
{
    Node *curr = root;
    for (int i = 0; i < n; i++)
    {
        if (curr->next[s[i] - 'a'] == NULL)
        {
            curr->next[s[i] - 'a'] = new Node();
        }
        curr = curr->next[s[i] - 'a'];
    }
    curr->end = 1;
}

bool search(string s, int n)
{
    Node *curr = root;
    for (int i = 0; i < n; i++)
    {
        if (curr->next[s[i] - 'a'] == NULL)
        {
            return false;
        }
        curr = curr->next[s[i] - 'a'];
    }
    return curr->end;
}

void del(Node *curr)
{
    for (int i = 0; i < 26; i++)
    {
        if (curr->next[i])
        {
            del(curr->next[i]);
        }
    }
    delete curr;
}

int main()
{
    while (true)
    {
        cout << endl
             << "Option 1: Enter a string" << endl
             << "Option 2: Search string" << endl
             << "Option 3: Exit" << endl;
        int q;
        string s;
        cin >> q;

        if (q == 1)
        {
            cout << endl
                 << "Please enter a string: ";
            cin >> s;
            insert(s, s.size());
        }
        else if (q == 2)
        {
            cout << endl
                 << "Please enter search string: ";
            cin >> s;
            if (search(s, s.size()))
            {
                cout << endl
                     << "String found" << endl;
            }
            else
            {
                cout << endl
                     << "String is not found" << endl;
            }
        }
        else if (q == 3)
        {
            break;
        }
        else
        {
            cout << endl
                 << "Invalid input" << endl;
        }
    }
    del(root);
}
