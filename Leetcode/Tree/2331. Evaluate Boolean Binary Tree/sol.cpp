#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool evaluateTree(TreeNode *root)
{
    if (root->val == 0 || root->val == 1)
        return root->val;

    else if (root->val == 2)
        return evaluateTree(root->left) || evaluateTree(root->right);

    else
        return evaluateTree(root->left) && evaluateTree(root->right);
}

int main()
{

    return 0;
}