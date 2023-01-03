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

pair<bool, int> isSumTreeFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = root->data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if (left && right && condn)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    return ans;
}

bool isSumTree(Node *root)
{
    if(isSumTreeFast(root).first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    createTree(root);

    if(isSumTree(root))
    {
        cout << "Yes, sum tree" << endl;
    }
    else
    {
        cout << "NO, not a sum tree" << endl;
    }

    return 0;
}