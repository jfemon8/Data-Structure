#include <bits/stdc++.h>
using namespace std;

void insertHeap(vector<int> &v, int val)
{
    v.push_back(val);
    int curr = v.size() - 1;
    while (curr != 0)
    {
        int par = (curr - 1) / 2;
        if (v[par] < v[curr])
        {
            swap(v[par], v[curr]);
            curr = par;
        }
        else
        {
            break;
        }
    }
}

void deleteHeap(vector<int> &v)
{
    if (v.size() == 0)
    {
        cout << endl
             << "The Heap is empty." << endl;
        return;
    }
    v[0] = v[v.size() - 1];
    v.pop_back();
    int curr = 0;
    while (true)
    {
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        if (left < v.size() && right < v.size())
        {
            if (v[left] >= v[right] && v[curr] < v[left])
            {
                swap(v[left], v[curr]);
                curr = left;
            }
            else if (v[left] <= v[right] && v[curr] < v[right])
            {
                swap(v[right], v[curr]);
                curr = right;
            }
            else
            {
                break;
            }
        }
        else if (left < v.size() && v[curr] < v[left])
        {
            swap(v[left], v[curr]);
            curr = left;
        }
        else if (right < v.size() && v[curr] < v[right])
        {
            swap(v[right], v[curr]);
            curr = right;
        }
        else
        {
            break;
        }
    }
}

void printHeap(vector<int> v)
{
    cout << endl;
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    int n;
    cout << endl
         << "Please enter the Heap size: ";
    cin >> n;
    cout << endl
         << "Please enter " << n << " nodes: ";
    for (int i = 0; i < n; i++)
    {
        int node;
        cin >> node;
        insertHeap(v, node);
    }
    while (true)
    {
        int op;
        cout << endl
             << "Option 1: Insert value" << endl
             << "Option 2: Delete value" << endl
             << "Option 3: Print Heap" << endl
             << "Option 4: Exit" << endl
             << endl
             << "Please enter an option: ";
        cin >> op;
        if (op == 1)
        {
            int node;
            cout << endl
                 << "Please enter the value: ";
            cin >> node;
            insertHeap(v, node);
        }
        else if (op == 2)
        {
            deleteHeap(v);
        }
        else if (op == 3)
        {
            printHeap(v);
        }
        else if (op == 4)
        {
            break;
        }
        else
        {
            cout << endl
                 << "Invalid option" << endl;
        }
    }

    return 0;
}
