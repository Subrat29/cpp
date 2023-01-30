#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

//1st solution : byself
int solve(TreeNode *root, int &sum)
{
    if (root == NULL)
        return sum;

    return max(solve(root->left, sum) + 1, solve(root->right, sum) + 1);
}

int maxDepth(TreeNode *root)
{
    int sum = 0;
    return solve(root, sum);
}


// 2nd solution
int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{

    return 0;
}