#include <bits/stdc++.h> //Iterative solution using stack --- O(n) time and O(n) space;
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

/*
vector<int> preorderTraversal(TreeNode *root)         //from postorder approach
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *last = NULL; //extra

    while (root || !s.empty())
    {
        if (root)
        {
            ans.push_back(root->val);
            s.push(root); //push all node
            root = root->left;
        }
        else
        {
            TreeNode *top = s.top();
            if (top->right && last != top->right)
            {
                root = top->right;
            }
            else
            {
                last = top;
                s.pop();
            }
        }
    }
    return ans;
}
*/

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> s;

    while (root || !s.empty())
    {
        if (root)
        {
            ans.push_back(root->val);
            if (root->right)
            {
                s.push(root->right);
            }
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
        }
    }
    return ans;
}

int main()
{

    return 0;
}