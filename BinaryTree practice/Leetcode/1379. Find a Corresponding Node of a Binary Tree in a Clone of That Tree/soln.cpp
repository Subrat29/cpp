#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

/*
    void preorder(TreeNode *orig, TreeNode *copy, TreeNode *target, TreeNode *&ans)
    {
        if(orig == NULL)
        return;

        if(orig == target)
        ans = copy;

        preorder(orig->left, copy->left, target, ans);
        preorder(orig->right, copy->right, target, ans);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        TreeNode *ans = NULL;
        preorder(original, cloned, target, ans);
        return ans;
    }
*/

TreeNode *ans = NULL;
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    if (cloned == NULL)
        return cloned;

    if (cloned->val == target->val)      // hm yha node nhi compare kra skte varna bc target ke left, right null hoge but cloned ke nhi...
        ans = cloned;

    getTargetCopy(original, cloned->left, target);
    getTargetCopy(original, cloned->right, target);

    return ans;
}

int main()
{

    return 0;
}