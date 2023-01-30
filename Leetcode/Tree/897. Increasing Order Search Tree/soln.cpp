#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void inorder(TreeNode *root, queue <TreeNode*> &q)
{
    if (root == NULL)
        return;

    inorder(root->left, q);
    q.push(root);
    inorder(root->right, q);
}

TreeNode *increasingBST(TreeNode *root)
{
    queue <TreeNode*> q;
    inorder(root, q);

    TreeNode *node = q.front();
    q.pop();

    TreeNode *ans = node;

    while (!q.empty())
    {
        node->right = q.front();
        node->left = NULL;
        q.pop();
        node = node->right; 
    }
    node->right = NULL;
    node->left = NULL;
    
    return ans;
}

int main()
{

    return 0;
}