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

void solve(Node *root, int &count, int k, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    // left
    solve(root->left, count, k, path);
    // right
    solve(root->right, count, k, path);

    // check for k sum

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}

int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, count, k, path);
    return count;
}

int main()  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    int k = 8;
    cout << "No of path which has sum k : " << sumK(root, k);
    return 0;
}