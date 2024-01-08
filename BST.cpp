#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertTree()
{
    int data;
    Node *root;
    cin >> data;
    if (data == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(data);
    }

    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        Node *pr = q.front();
        q.pop();

        int l, r;
        Node *left, *right;
        cin >> l >> r;
        if (l == -1)
        {
            left = NULL;
        }
        else
        {
            left = new Node(l);
        }
        if (r == -1)
        {
            right = NULL;
        }
        else
        {
            right = new Node(r);
        }
        pr->left = left;
        pr->right = right;

        if (pr->left)
        {
            q.push(pr->left);
        }
        if (pr->right)
        {
            q.push(pr->right);
        }
    }

    return root;
}

Node *insertArray(vector<int> v, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int mid = (l + r) / 2;
    Node *root = new Node(v[mid]);
    root->left = insertArray(v, l, mid - 1);
    root->right = insertArray(v, mid + 1, r);
    return root;
}

Node *insertNode(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->val > data)
    {
        if (root->left == NULL)
        {
            root->left = new Node(data);
        }
        else
        {
            root->left = insertNode(root->left, data);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << endl
             << "The tree is empty." << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    cout << endl;
    while (!q.empty())
    {
        Node *pr = q.front();
        q.pop();

        cout << pr->val << " ";

        if (pr->left)
        {
            q.push(pr->left);
        }
        if (pr->right)
        {
            q.push(pr->right);
        }
    }
    cout << endl;
}

void search(Node *root, int x)
{
    if (root == NULL)
    {
        cout << endl
             << x << " is not found in the tree." << endl;
        return;
    }
    if (root->val == x)
    {
        cout << endl
             << x << " is found in the three." << endl;
        return;
    }
    if (root->val > x)
    {
        search(root->left, x);
    }
    else
    {
        search(root->right, x);
    }
}

int main()
{
    cout << endl
         << "Option 1: Insert a BST" << endl
         << "Option 2: Insert an Array" << endl
         << endl
         << "Please choose an option: ";
    int option;
    Node *root;
    cin >> option;
    if (option == 1)
    {
        cout << endl
             << "Insert the nodes of the tree: ";
        root = insertTree();
    }
    else if (option == 2)
    {
        int n;
        cout << endl
             << "Enter the size of the array: ";
        cin >> n;
        vector<int> a(n);
        cout << endl
             << "Enter the array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        root = insertArray(a, 0, n - 1);
    }
    else
    {
        cout << endl
             << "Invalid option." << endl;
        return 0;
    }
    while (true)
    {
        int op;
        cout << endl
             << endl
             << "Option 1: Search a value" << endl
             << "Option 2: Insert a Node" << endl
             << "Option 3: Print the BST" << endl
             << "Option 4: Exit" << endl
             << endl
             << "Please enter an option: ";
        cin >> op;
        if (op == 1)
        {
            int s;
            cout << endl
                 << "Please enter the search value: ";
            cin >> s;
            search(root, s);
        }
        else if (op == 2)
        {
            int n;
            cout << endl
                 << "Please insert the node value: ";
            cin >> n;
            root = insertNode(root, n);
        }
        else if (op == 3)
        {
            printLevelOrder(root);
        }
        else if (op == 4)
        {
            break;
        }
        else
        {
            cout << endl
                 << "Invalid input." << endl;
        }
    }
    return 0;
}
