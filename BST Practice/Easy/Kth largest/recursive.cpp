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

void insertToBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
    }

    else if (root->data > data)
    {
        insertToBST(root->left, data);
    }

    else
    {
        insertToBST(root->right, data);
    }
}

void inputBST(Node *&root)
{
    cout << "Enter data: ";
    int data;
    cin >> data;

    while (data != -1)
    {
        insertToBST(root, data);
        cin >> data;
    }
}

int solve(Node *root, int &i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    // left
    int left = solve(root->left, i, k);

    if (left != -1)
        return left;

    // Node
    i++;
    if (i == k)
        return root->data;

    // right
    int right = solve(root->right, i, k);
}

int kthlargest(Node *root, int k)
{
    int i = 0;
    return solve(root, i, k);
}

void inorder(Node *root, int &noOfNode)
{
    if (root == NULL)
        return;

    inorder(root->left, noOfNode);
    cout << root->data << " ";
    noOfNode++;
    inorder(root->right, noOfNode);
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;
    inputBST(root);

    int noOfNode = 0;
    
    cout << "Inorder: ";
    inorder(root, noOfNode);
    cout << endl;

    int kthLargest = 5;
    int kthSmallest = noOfNode - kthLargest + 1;

    cout << kthLargest << "th largest element: " << kthlargest(root, kthSmallest);
}