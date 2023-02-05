#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
};

int nodesCount(struct Node *tree)
{
    if (tree == NULL)
        return 0;

    int ans = nodesCount(tree->left) + nodesCount(tree->right) + 1; //+1 for include root node
    return ans;
}

bool isCBT(struct Node *tree, int i, int cnt) // cbt means phle left me dlegi node
{
    if (tree == NULL)
        return true;

    if (i >= cnt)
    {
        return false;
    }
    else
    {
        bool left = isCBT(tree->left, 2 * i + 1, cnt);
        bool right = isCBT(tree->right, 2 * i + 2, cnt);
        return left && right;
    }
}

bool ismaxHeap(struct Node *tree)
{
    // leaf Node
    if (tree->left == NULL && tree->right == NULL)
        return true;

    if (tree->right == NULL)
    {
        return (tree->data > tree->left->data);
    }
    else
    {
        bool left = ismaxHeap(tree->left);
        bool right = ismaxHeap(tree->right);

        return (left && right && tree->data > tree->left->data &&
                tree->data > tree->right->data);
    }
}

bool isHeap(struct Node *tree)
{
    // step1: check heap is complete binary tree or not
    // step2: check heap is maxheap or not

    int index = 0;
    int nodeCount = nodesCount(tree);
    return isCBT(tree, index, nodeCount) && ismaxHeap(tree);
}

int main()
{

    return 0;
}