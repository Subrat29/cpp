#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    //constructor
    Node (int d)
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

    if(data == -1)
    return NULL;

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

//3 other Types of Traversals 

void inorder(Node *root)
{
    //base case
    if(root == NULL)
    return;

    inorder(root->left);
    cout << root->data << " " ;
    inorder(root->right);
}

void preorder(Node *root)
{
    //base case
    if(root == NULL)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    //base case
    if(root == NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()                                                  // Input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;

    root = createTree(root);                                  //very common to forget this "root ="

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl << "Preorder Traversal: ";
    preorder(root);

    cout << endl << "Postorder Traversal: ";
    postorder(root);

    return 0;
}