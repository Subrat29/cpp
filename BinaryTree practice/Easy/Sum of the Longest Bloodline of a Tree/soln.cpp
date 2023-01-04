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

Node *createTree(Node *root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen) // forget & in maxLen, maxSum
{
    if (root == NULL) // forget
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }

        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return; // forget
    }

    sum = sum + root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen); // forget +1
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;  // i did maxSum = 0;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}

int main() // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
{
    Node *root = NULL;
    root = createTree(root);

    int ans = sumOfLongRootToLeafPath(root);
    cout << ans;

    return 0;
}