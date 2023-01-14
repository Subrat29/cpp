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
//------------------------------------------------------------------------------------------------------------------------------------------------------
class info
{
public:
    //     int mini;
    //     int maxi;
    //     int size;
    //     bool isBST;

    int maxi;
    int mini; // Note: i rearrange this then it run;
    bool isBST;
    int size;
};

info solve(Node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        //  return {INT_MIN, INT_MAX, 0, true};
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    // if (left.isBST && right.isBST && (root->data > left.mini && root->data < right.maxi))   // mistake
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int findLargestBST(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main() // 50 20 10 30 70 90 110 -1
{
    Node *root = NULL;
    inputBST(root);

    cout << "Size of BST: " << findLargestBST(root);
}