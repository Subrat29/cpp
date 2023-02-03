#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void solve(TreeNode *root, string &s)
{
    if (root == NULL)
        return;

    s = s + to_string(root->val);

    if (root->left) // left side check
    {
        s = s + '(';
        solve(root->left, s);
        s = s + ')';
    }

    if (root->right) // right side check
    {
        if (root->left == NULL) // left side not present, but right side
            s = s + "()";

        s = s + '(';
        solve(root->right, s);
        s = s + ')';
    }
}

string tree2str(TreeNode *root)
{
    string ans;
    solve(root, ans);
    return ans;
}

int main()
{

    return 0;
}
