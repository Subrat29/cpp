#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *solve(vector<int> &nums, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;
    TreeNode *temp = new TreeNode(nums[mid]);

    temp->left = solve(nums, left, mid - 1);
    temp->right = solve(nums, mid + 1, right);

    return temp;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return solve(nums, 0, nums.size() - 1);
}

int main()
{

    return 0;
}