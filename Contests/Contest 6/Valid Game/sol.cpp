#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// approch: check inorder is sorted or not

void findInorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    findInorder(root->left, in);
    in.push_back(root->data);
    findInorder(root->right, in);
}

int validGame(TreeNode<int> *root)
{

    vector<int> in;
    findInorder(root, in);

    for (int i = 0; i < in.size() - 1; i++)
    {
        if (in[i] >= in[i + 1])
            return 0;
    }

    return 1;
}

int main()
{

    return 0;
}