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

Node *insert()
{
    Node *root;
    int v;
    cin >> v;
    if (v == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(v);
    }
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        Node *p = q.front();
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
        p->left = left;
        p->right = right;

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    return root;
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        cout << p->val << " ";

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    cout << endl;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = countNode(root->left);
    int r = countNode(root->right);
    return l + r + 1;
}

int countLeafNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int l = countLeafNode(root->left);
    int r = countLeafNode(root->right);
    return l + r;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

int main()
{
    cout << "Please insert the tree:" << endl;
    Node *root = insert();
    while (true)
    {
        cout << endl
             << "Option 1: Print in PreOrder" << endl
             << "Option 2: Print in PostOrder" << endl
             << "Option 3: Print in InOrder" << endl
             << "Option 4: Print in LevelOrder" << endl
             << "Option 5: Total Number of Nodes" << endl
             << "Option 6: Number of Leaf Nodes" << endl
             << "Option 7: Height of the Tree" << endl
             << "Option 8: Exit" << endl
             << endl
             << "Please choose an option: ";
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << endl;
            preOrder(root);
            cout << endl;
        }
        else if (n == 2)
        {
            cout << endl;
            postOrder(root);
            cout << endl;
        }
        else if (n == 3)
        {
            cout << endl;
            inOrder(root);
            cout << endl;
        }
        else if (n == 4)
        {
            cout << endl;
            levelOrder(root);
        }
        else if (n == 5)
        {
            cout << endl
                 << "Total number of Nodes: " << countNode(root) << endl;
        }
        else if (n == 6)
        {
            cout << endl
                 << "Total number of leaf Nodes: " << countLeafNode(root) << endl;
        }
        else if (n == 7)
        {
            cout << endl
                 << "Height of the tree is: " << height(root) << endl;
        }
        else if (n == 8)
        {
            break;
            ;
        }
        else
        {
            cout << endl
                 << "Invalid option" << endl;
        }
    }

    return 0;
}
