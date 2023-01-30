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

Node *createTree(Node *root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    // if (root->left)                                    Mistake use this
        root->left = createTree(root->left);
    // if (root->right)
        root->right = createTree(root->right);

    return root;
}

void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    // reach new level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    vector<int> ans = leftView(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";      // full ans nhi print hora only 1 print
    }

    return 0;
}