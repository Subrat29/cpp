#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

struct Node *getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node *root, vector<int> &in) // lnr
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

void preorder(Node *root, vector<int> &in, int &i) // nlr    //forget & in i
{
    if (root == NULL)
        return;

    root->data = in[i++];
    preorder(root->left, in, i);
    preorder(root->right, in, i);
}

void BSTToMinHeap(Node *root)
{
    vector<int> in;

    // step1: find inorder of tree
    inorder(root, in);

    int i = 0;
    // step2: Now, fill inorder by preorder traversal
    preorder(root, in, i);
}

void preorderTaversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTaversal(root->left);
    preorderTaversal(root->right);
}

int main()
{
    // BST formation
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    cout << "Bst: ";
    preorderTaversal(root);

    cout << endl;

    BSTToMinHeap(root);

    cout << "Min Heap: ";
    preorderTaversal(root);

    return 0;
}
