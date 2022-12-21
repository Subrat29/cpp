#include <bits/stdc++.h>
using namespace std;

class Node // () nhi aata isme
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

Node *createTree(Node *&root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    root->left = createTree(root->left);
    root->right = createTree(root->right);
    return root;
}

int height(Node *root)
{
    //base case
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;

    return ans;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;

    createTree(root);
    cout << "Height of Tree: " << height(root);

    return 0;
}