#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void preorder(vector<int> &ans, TreeNode *root)
{
    if (root == NULL)
        return;

    ans.push_back(root->val);
    preorder(ans, root->left);
    preorder(ans, root->right);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(ans, root);
    return ans;
}

int main()
{

    return 0;
}