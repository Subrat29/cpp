#include <bits/stdc++.h>  //Morris traversal --- O(n) time and O(1) space.
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;

    while (root)
    {
        if (root->left)
        {
            Node *pre = root->left; // predecessor
            while (pre->right && pre->right != root)
            {
                pre = pre->right;
            }

            if (!pre->right) // if pred ka right null aa jaye to, create link to root node
            {
                pre->right = root;
                root = root->left;
            }

            else // remove link
            {
                pre->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }

        else
        {
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;

    return 0;
}