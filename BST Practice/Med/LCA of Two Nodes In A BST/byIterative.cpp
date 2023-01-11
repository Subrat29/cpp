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

Node *LCAinaBST(Node *root, Node *P, Node *Q)                // tc: O(N), sc: O(1)
{
    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
        {
            root = root->right;
        }

        else if (root->data > P->data && root->data > Q->data)
        {
            root = root->left;
        }
        
        else
            return root;
    }
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;

    inputBST(root);

    Node *P = root->left->left;
    Node *Q = root->left;

    cout << "Least common ancestor: " << LCAinaBST(root, P, Q)->data << endl;
}