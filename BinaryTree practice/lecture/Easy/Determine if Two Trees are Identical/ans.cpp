#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(Node *root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 != NULL && r2 == NULL)
        return false;

    if (r1 == NULL && r2 != NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value;
    if (r1->data == r2->data)
        value = true;
    else
        value = false;

    if (left && right && value)
        return true;
    else
        return false;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    Node *root2 = NULL;
    root2 = createTree(root2);

    if (isIdentical(root, root2))
    {
        cout << "Identical" << endl;
    }
    else
    {
        cout << "Not Identical" << endl;
    }

    return 0;
}