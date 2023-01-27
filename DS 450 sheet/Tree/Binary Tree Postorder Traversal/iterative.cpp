#include <bits/stdc++.h> //Iterative solution using stack --- O(n) time and O(n) space;
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *last = NULL;

    while (root || !s.empty())
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }

        else // forgot this else
        {
            TreeNode *top = s.top();
            if (top->right && last != top->right) // use top not root
            {
                root = top->right; // root me dal do ise
            }
            else
            {
                ans.push_back(top->val);
                last = top;
                s.pop();
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}