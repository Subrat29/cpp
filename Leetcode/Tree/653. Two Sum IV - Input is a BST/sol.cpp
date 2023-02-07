#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

void inorder(TreeNode *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

bool findTarget(TreeNode *root, int k)
{
    // step1: store inorder of tree

    vector<int> in;
    inorder(root, in);

    // step2: check if 2 elem has sum = k

    int i = 0;
    int j = in.size() - 1;

    while (i < j)
    {
        if (in[i] + in[j] == k)
            return true;
        else if (in[i] + in[j] < k)
            i++;
        else
            j--;
    }

    return false;
}

int main()
{

    return 0;
}