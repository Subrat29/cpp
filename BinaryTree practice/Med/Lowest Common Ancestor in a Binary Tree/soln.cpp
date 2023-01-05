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

    // if (root->left)  // mistake
        root->left = createTree(root->left);
    // if (root->right)
        root->right = createTree(root->right);

    return root;
}

Node *lca(Node *root, int n1, int n2)         //lowest common ancestor : lowest means jo anscestor sabse phle aaye not chota.
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }

    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;

    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;

    else
        return NULL;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    int n1 = 7;
    int n2 = 11;

    Node *ans = lca(root, n1, n2);    
    cout << "Lowest common ancestor: " << lca(root, n1, n2)->data;

    return 0;
}