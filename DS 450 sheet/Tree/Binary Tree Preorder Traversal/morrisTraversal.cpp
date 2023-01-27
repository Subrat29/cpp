#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    while (root)
    {
        if (root->left)
        {
            TreeNode *pred = root->left; // predcessor: ek left bhejo then right bhejte rho jab tk null na aye
            while (pred->right && pred->right != root)
            {
                pred = pred->right;
            }

            if (!pred->right) // ped ka link root node se kr do if pred right null ho to
            {
                pred->right = root;
                ans.push_back(root->val);
                root = root->left;
            }
            else // Node, link remove krdo jo uparBanaye the
            {
                pred->right = NULL;
                root = root->right;
            }
        }
        else
        {
            ans.push_back(root->val);
            root = root->right;
        }
    }
    return ans;
}

int main()
{

    return 0;
}