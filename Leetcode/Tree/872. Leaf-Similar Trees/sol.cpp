#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void solve(TreeNode *root, vector<int> &v) // if stack use then error de rha h
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        v.push_back(root->val);

    solve(root->left, v);
    solve(root->right, v);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> a, b;
    solve(root1, a);
    solve(root2, b);

    // for (int i = 0; i < a.size(); i++)         // if a = 6 7 4 9 8 ,  b = 6 7 4 9 8 10  then it return true but ans is false
    // {
    //     if (a[i] != b[i])
    //         return false;
    // }

    return a == b;
}

int main()
{

    return 0;
}