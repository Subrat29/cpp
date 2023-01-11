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

void insertInBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
    }

    else if (data < root->data)      // insert in left part
    {
        insertInBST(root->left, data);
    }

    else                             // insert in right part
    {
        insertInBST(root->right, data);
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

int Min(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int Max(Node *root)
{
    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int main()
{
    Node *root = NULL;

    inputBST(root);

    cout << "Minimum element of BST: " << Min(root) << endl;
    cout << "Maximum element of BST: " << Max(root) << endl;
}