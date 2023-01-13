#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertInBST(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
    }

    else if (root->data > x)
    {
        insertInBST(root->left, x);
    }

    else
    {
        insertInBST(root->right, x);
    }
}

void inputBST(Node *&root)
{
    cout << "Enter data: ";
    int data;
    cin >> data;

    while (data != -1)
    {
        insertInBST(root, data);
        cin >> data;
    }
}

void lot(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inOrder(Node *root, vector<Node*> &v)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, v);
    v.push_back(root);
    inOrder(root->right, v);
}

Node *flatten(Node *root)
{
    // 1st step
    vector<Node*> v;
    inOrder(root, v);

    Node *flat = v[0];
    Node *curr = flat;

    // 2nd step
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = v[i];

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // 3rd step
    curr->left = NULL;
    curr->right = NULL;

    return flat;
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;
    inputBST(root);
    cout << "BST: " << endl;
    lot(root);

    Node *ans = flatten(root);
    cout << "Flatten BST: " << endl;
    lot(ans);

    return 0;
}