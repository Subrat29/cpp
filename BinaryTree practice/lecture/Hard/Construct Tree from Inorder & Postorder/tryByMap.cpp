#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void mapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &Index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    // base case
    if (Index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = post[Index--];
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    // recursive calls
    root->right = solve(in, post, Index, position + 1, inorderEnd, n, nodeToIndex);
    root->left = solve(in, post, Index, inorderStart, position - 1, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    // create a map for mapping node to index
    map<int, int> nodeToIndex;
    mapping(in, nodeToIndex, n);

    int postOrderIndex = n - 1;
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);

    return ans;
}

void preorder(Node *root) // LRN
{
    // base case
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    //  Output: 1 2 4 8 5 3 6 7
    int n = 8;

    cout << "Inorder: ";
    for (int i = 0; i < n; i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int i = 0; i < n; i++)
    {
        cout << post[i] << " ";
    }
    cout << endl;

    Node *ans = buildTree(in, post, n);

    cout << "Pre order: ";
    preorder(ans);
}