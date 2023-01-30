#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        double sum=0; 
        int l = q.size();

        for (int i = 0; i < l; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            sum = sum + temp->val;
        }
        res.push_back(sum / l); 
    }
    return res;
}

int main()
{

    return 0;
}