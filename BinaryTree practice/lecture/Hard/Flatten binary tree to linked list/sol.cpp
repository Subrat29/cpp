#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void flatten(Node *root)
{
    Node *curr, *pred;        //predecessor
    curr = root;
    while (curr != NULL)
    {
        if(curr->left)
        {
            pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }

            pred->right = curr->right;  // L -> R ,  left part ka right part se link
            curr->right = curr->left;   // N -> L ,  curr node ka left se link   
            curr->left = NULL;          // left link ko null krete jao
        }
        curr = curr->right;
    }
}

void preOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = buildTree(root);

    cout << "By preorder: ";
    preOrder(root);
    cout << endl;

    flatten(root);

    cout << "List Traversal: ";
    print(root);

    return 0;
}