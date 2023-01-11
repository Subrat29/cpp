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

void morrisTraversal(Node *root)
{
    Node *pred, *current;

    if (root == NULL)
    {
        return;
    }

    current = root;
    while (current != NULL) 
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;       // mis use left
        }

        else
        {
            // Find the inorder predecessor of current
            pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;                                         // why we change pred now to line 55 --> for understand go to video or dry run 
            }
        }

        if (pred->right == NULL)
        {
            pred->right = current;
            current = current->left;
        }

        else
        {
            pred->right = NULL;
            cout << current->data << " ";
            current = current->right;
        }
    }
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = buildTree(root);

    morrisTraversal(root);

    return 0;
}