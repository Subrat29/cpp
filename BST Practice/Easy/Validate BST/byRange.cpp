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

bool isBST(Node *root, int min, int max)
{
    //base case
    if(root == NULL)
    {
        return true;
    }

    if(root->data > min && root->data < max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool validateBST(Node *root)    
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;

    inputBST(root);

    if (validateBST(root))
    {
        cout << "Valid BST";
    }
    else
    {
        cout << "Not Valid BST";
    }
}