#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *right;
    TreeNode *left;
};

int solve(TreeNode *root, int sum)
{
    if (root == NULL)
        return 0;

    sum = 2 * sum + root->val;

    if (!root->left && !root->right)
        return sum;

    return solve(root->left, sum) + solve(root->right, sum);
}

int sumRootToLeaf(TreeNode *root)
{
    return solve(root, 0);
}

int main()
{

    return 0;
}