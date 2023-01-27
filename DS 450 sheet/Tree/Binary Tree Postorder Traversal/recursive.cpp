#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void postorder(vector<int> &ans, TreeNode *root) // lrn
{
    if (root == NULL)
        return;

    postorder(ans, root->left);
    postorder(ans, root->right);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(ans, root);
    return ans;
}

int main()
{

    return 0;
}