#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void solve(TreeNode *root, vector<string> &ans, string &str)
{
    if (root == NULL)
        return;

    if (root->left || root->right)
    {
        str = str + to_string(root->val) + "->";
    }
    else
    {
        str = str + (to_string(root->val));
        ans.push_back(str);
    }

    solve(root->left, ans, str);
    solve(root->right, ans, str);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string str = "";
    solve(root, ans, str);

    return ans;
}

int main()
{

    return 0;
}