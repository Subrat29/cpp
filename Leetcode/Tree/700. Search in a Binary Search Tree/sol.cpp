#include <bits/stdc++.h> //Doubt = how to use inorder traversal using return funtion not void function
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 1st solution
void inorder(TreeNode *root, int val, TreeNode *&ans)
{
    if (root == NULL)
        return;

    inorder(root->left, val, ans);
    if (root->val == val)
        ans = root;
    inorder(root->right, val, ans);
}

TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *ans = NULL; // Remember: if null se initialize nhi kiya to error aa jata h
    inorder(root, val, ans);
    return ans;
}

// 2nd solution
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    if (root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

int main()
{

    return 0;
}