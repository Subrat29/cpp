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
        this->right = NULL;
        this->left = NULL;
    }
};

Node *buildTree(Node *root) // build or create a tree
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node *root, int &cnt)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, cnt);

    if(root->left == NULL && root->right == NULL)
    {
        cnt++;
    }

    inorder(root->right, cnt);
}

int noOfLeafNodes(Node *root) // by inorder traversal
{
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;

    root = buildTree(root);
    cout << "No of leaf Nodes are: " << noOfLeafNodes(root) <<endl;

    return 0;
}